from sys import stdin,stdout
inp=lambda :(int(i) for i in  stdin.readline().split())
n,k=inp()
a=sorted(list(inp()))
print(-1) if k>n else print(a[-k],0)