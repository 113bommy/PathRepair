n = int(input())
num = list(map(int,list(input())))
f = list(map(int,input().split()))
f = [0]+f
out = -2
for i in range(n):
    if num[i]<f[num[i]]:
        out = i
        break
if out != -2:
    for i in range(out,n):
        if num[i]<=f[num[i]]:
            num[i] = f[num[i]]
        else:
            break
print("".join(map(str,num)))