import sys
input = lambda: sys.stdin.readline().rstrip()

def calc(x):
    n = int(x * 10 ** 9 + 0.5)
    a = 0
    b = 0
    while n % 2 == 0:
        n //= 2
        a += 1
    while n % 5 == 0:
        n //= 5
        b += 1
    return (min(a, 18), min(b, 18))

ans = 0
N = int(input())
X = [[0] * 19 for _ in range(19)]
for _ in range(N):
    a, b = calc(float(input()))
    if a >= 9 and b >= 9:
        ans -= 1
    X[a][b] += 1

Y = [x[:] for x in X]

for i in range(18)[::-1]:
    for j in range(19):
        Y[i][j] += Y[i+1][j]
for i in range(19):
    for j in range(18)[::-1]:
        Y[i][j] += Y[i][j+1]

for i in range(19):
    for j in range(19):
        ans += X[i][j] * Y[18-i][18-j]
print(ans // 2)
