n,l=map(int,input().split())
a=[input() for _ in range(n)]
a.sort()
print(*a,sep="")