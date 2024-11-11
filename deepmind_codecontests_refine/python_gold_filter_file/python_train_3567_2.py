import sys;input=sys.stdin.readline
N, a, b, c, k = map(int, input().split())
X = list(map(int, input().split()))
x, y = 0, 10**18
R = 10**18
for i in range(N):
    mnc = min(a*(X[i]+2), a+b)
    if i == N-2:
        R = min(x,y)+X[-1]*a+c+min(a*(X[-2]+2), a+b)+k
    x, y = min(x+a*X[i]+c, y+mnc), x + mnc + 2*k
print(min([R,x,y])+k*(N-1))
