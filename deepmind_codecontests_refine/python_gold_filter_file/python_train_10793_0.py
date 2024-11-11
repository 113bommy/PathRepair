def r(a, b):
    ans = a // b
    if a % b != 0:
        ans += 1
    return ans


n, x, y = map(int, input().split())
a = list(input()) + ['1']

count = 0
for i in range(1, n + 1):
    if a[i] == '1' and a[i - 1] == '0':
        count += 1
ans = 999999999999999999
if count == 0:
    print(0)
    exit()
for i in range(count):
    ans = min(ans, min(x, y) * i + y * (count - i))
print(ans)
