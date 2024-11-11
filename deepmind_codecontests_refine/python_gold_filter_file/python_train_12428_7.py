n = int(input())

ar = list(map(int, input().split()))

ar.sort()

ans = 0

for i in range(n):
    ans += abs(ar[i] - (i + 1))

print(ans)
