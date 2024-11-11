n, m = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
t = n
for i in range(1, m):
    cai = a.count(i)
    ans += cai * (t - cai)
    t -= cai
print(ans)
