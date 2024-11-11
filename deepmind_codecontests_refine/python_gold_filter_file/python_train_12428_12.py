n = int(input())
b = list(map(int, input().split()))

b.sort()

ans = 0
for i in range(n):
    ans += abs(b[i] - i - 1)

print(ans)
