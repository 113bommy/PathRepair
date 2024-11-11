a, b = map(int, input().split())
s=sorted([input() for i in range(a)])
print(*s,sep="")