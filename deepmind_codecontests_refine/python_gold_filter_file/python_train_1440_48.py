n,x=map(int,input().split())
m=[int(input()) for i in range(n)]
x-=sum(m)
print(n+x//min(m))