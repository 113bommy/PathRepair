n, x, m = map(int, input().split())

lst, num, flag = set(), [], False
for i in range(1, n + 1):
    lst.add(x), num.append(x)
    x = x ** 2 % m
    if x in lst:
        flag = True
        break

ans = sum(num)
if flag:
    cnt, idx = i, num.index(x)
    div, mod = divmod(n - cnt, len(num) - idx)
    ans += sum(num[idx:idx + mod])
    ans += sum(num[idx:]) * div
print(ans)
