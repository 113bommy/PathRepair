a = input()
r = 0
b = list(map(str,input().split()))

for i in range(5):
    if b[i][0]==a[0] or b[i][1]==a[1]:r = 1;break
    else:r = 0
if r:print("YES")
else:print("NO")