N = int(input())
F = [int(input().replace(' ', ''), 2) for _ in range(N)]
P = [[int(_) for _ in input().split()] for _ in range(N)]

ans = - 10 ** 10
for i in range(1, 2 ** 10):
    ans = max(ans, sum([P[j][bin(i&F[j]).count('1')] for j in range(N)]))
print(ans)