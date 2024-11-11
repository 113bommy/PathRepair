N = int(input())
P = list(map(int, input().split()))

ans, i = 0, 0
while i < N:
    if i + 1 == P[i]:
        ans += 1
        i += 1
    i += 1

print(ans)
