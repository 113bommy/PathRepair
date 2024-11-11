from math import floor, log
inpl = lambda: list(map(int,input().split()))
N, K = inpl()
S = input()
U = S + S[::-1]
Sp = sorted([ U[i:i+N] for i in range(N+1)])[0]
n = 0
while Sp[n] == Sp[0]:
    n += 1

if K > int(floor(log(N/n)/log(2))) + 1:
    print(Sp[0]*N)
else:
    m = n * (2**(K-1))
    if m >= N:
        print(Sp[0]*N)
    else:
        print(Sp[0]*m + Sp[n:n+N-m])
