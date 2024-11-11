n=int(input())
a=list(map(int,input().split()))
m=int(input())
s=sum(a)
for i in range(m):
    p,x=map(int,input().split())
    print(s-a[p-1]+x)