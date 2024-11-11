N,L = map(int,input().split())
S = sorted([input() for _ in range(N)])
print(*S,sep='')
