N,L=map(int, input().split())
l=[input() for i in range(N)]
l.sort()
print(*l,sep="")