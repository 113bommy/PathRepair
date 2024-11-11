L,R= list(map(int, input().split()))
N = min(R-L+1,2019)
MOD = 2019
m = MOD

for i in range(L,L+N):
    for j in range(i+1,L+N):
        m = min(m,(i*j)%MOD)

print(m)