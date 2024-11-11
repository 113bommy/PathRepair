m,l = map(int,input().split())
s = sorted([input() for i in range(m)])
print(*s, sep="")