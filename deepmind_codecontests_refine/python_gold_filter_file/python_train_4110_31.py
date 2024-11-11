a, b, c, d = [int(x) for x in input().split(' ')]

m = max((3 * a) // 10, a - c * (a // 250))
v = max((3 * b) // 10, b - d * (b // 250))
if m > v:
    ans = 'Misha'
elif v > m:
    ans = 'Vasya'
else:
    ans = 'Tie'
print(ans)