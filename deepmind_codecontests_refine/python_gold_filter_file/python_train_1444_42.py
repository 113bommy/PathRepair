N = int(input())
S = int(input())

if N < S:
    print(-1)
    exit()
if N == S:
    print(N+1)
    exit()

rt = int(N**0.5)
for b in range(2,rt+1):
    a = 0
    n = N
    while n >= b:
        a += n%b
        n //= b
    a += n
    if a == S:
        print(b)
        exit()

d = N-S
divisors = set()
m = 1
while m*m <= d:
    if d%m == 0:
        divisors.add(m)
        divisors.add(d//m)
    m += 1

ans = INF = float('inf')

for p in divisors:
    if p > S: continue
    b = d // p + 1
    if b*b <= N: continue
    q = S - p
    if q >= b: continue
    ans = min(ans, b)

print(-1 if ans == INF else ans)