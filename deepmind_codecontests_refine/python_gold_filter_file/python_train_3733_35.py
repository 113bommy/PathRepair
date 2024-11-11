n=int(input())
a=list(map(int,input().split()))
m=int(input())
s=sum(a)
for i in range(m):
    p,x=map(int,input().split())
    print(s+x-a[p-1])
