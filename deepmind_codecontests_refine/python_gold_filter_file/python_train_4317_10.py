from bisect import bisect_left as bl
n=int(input())
a=list(map(int,input().split()))
m=int(input())
q=list(map(int,input().split()))
asu=[]
asu.append(a[0])
for i in range(1,n):
    asu.append(asu[-1]+a[i])

for i in range(m):
    print(bl(asu,q[i])+1)
