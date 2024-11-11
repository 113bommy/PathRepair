n = int(input())
s = [input() for i in range(n)]
MOD = n

def solve(add):
    for i in range(n):
        for j in range(n):
            if s[(i+add) % MOD][j] != s[(j+add) % MOD][i]:
                return False
    return True

ans = 0
for i in range(n):
    if solve(i):
        ans += n
print(ans)