a,b,c=  map(int,input().split())
M = 10**9
if c == M:l = [c]*b+[1]*(a-b)
else:l = [c]*b+[M]*(a-b)

print(*l)