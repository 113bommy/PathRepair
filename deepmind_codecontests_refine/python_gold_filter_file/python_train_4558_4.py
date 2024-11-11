N = int(input())
V = 0
E = 0
for i in range(N+1):
    V += i * (N-i+1)
for i in range(N-1):
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a
    E += a * (N-b+1)
ans = V - E
print(ans)
