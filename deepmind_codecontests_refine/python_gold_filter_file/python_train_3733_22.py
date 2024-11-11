n=int(input())
a=list(map(int,input().split()))
m=int(input())
for i in range(m):
    s,t=map(int,input().split())
    print(sum(a)-a[s-1]+t)