n, k = map(int, input().split())
a = list(sorted(map(int, input().split())))
ans = 0

for el in a:
    while k * 2 < el:
        k *= 2
        ans += 1
    k = max(k, el)

print(ans)
