n = int(input())
a = list(input())
a = list(map(int, a))
b = sorted(a[n:2*n])
a = sorted(a[0:n])
flag = 0
if a[0]>b[0]:
    flag = 1
for i in range(n):
    if flag:
        if a[i]<=b[i]:
            print("NO")
            exit(0)
    else:
        if a[i]>=b[i]:
            print("NO")
            exit(0)
print("YES")