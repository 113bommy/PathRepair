n = int(input())

a = []

for i in range(0,n+9):
    a.append(0)

for i in range(1,n):
    u,v = map(int,input().split())
    a[u] = a[u]+1
    a[v] = a[v]+1

flag = 1;

for i in range(1,n+1):
    if a[i]==2:
        flag = 0

if flag==0:
    print("NO")
else:
    print("YES")
