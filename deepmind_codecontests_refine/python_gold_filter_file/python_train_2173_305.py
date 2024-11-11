n,m=map(int,input().split())
a=[input() for i in range(n)]
a.sort()
print(*a,sep="")