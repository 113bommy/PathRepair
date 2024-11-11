from math import factorial
f = factorial
n = int(input())
a = [0] * 30
for i in range(n):
    s = input()
    a[ord(s[0]) - 97] += 1
ans = 0
for x in a:
    if x > 3:
        l = x // 2
        r = x - l
        ans += f(l) // (2 * (f(l - 2)))
        ans += f(r) // (2 * (f(r - 2)))
    elif x > 2:
        ans += 1
print(ans)
