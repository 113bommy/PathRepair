n,l = map(int,input().split())
x = [input() for i in range(n)]
x.sort()

print(*x,sep="")