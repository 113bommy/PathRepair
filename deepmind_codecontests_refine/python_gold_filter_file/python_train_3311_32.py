R,G,B,N, = list(map(int,input().split()))
s = 0
for r in range(N+1):
    for g in range(N+1):
        bp = N-r*R-g*G
        if bp>=0 and bp%B==0:
            s += 1
print(s)