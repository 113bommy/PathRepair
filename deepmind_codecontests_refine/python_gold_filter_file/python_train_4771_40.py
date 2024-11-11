n = int(input())
def calc(c, p):
    res = 0
    while c:
        res += c % p
        c = c // p
    return res
ans = n
for i in range(n+1):
    cand = calc(i, 6) + calc(n - i, 9)
    ans = min(ans, cand)
print(ans)
