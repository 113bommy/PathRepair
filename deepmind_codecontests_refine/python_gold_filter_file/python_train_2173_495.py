N,L = map(int,input().split())
S = sorted([input() for n in range(N)])
print(*S,sep="")