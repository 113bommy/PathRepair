n,x=map(int,input().split())
M=[int(input()) for i in range(n)]
x-=sum(M)
print(n+x//min(M))