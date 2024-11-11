import sys
n, m = map(int, input().split())
if n == m:
    print('01' * n)
    sys.exit(0)
if n > m + 1:
    print(-1)
    sys.exit(0)

if m > 2*(n+1):
    print(-1)
    sys.exit(0)

if m <= 2*(n-1):    #  0 _ 0 _ 0 _ 0
    t = m - (n - 1)
    ans = '011' * t
    if (n - 1) - t > 0:
        ans += '01' * (n - t - 1)
    ans = ans + '0'
else:               #  _ 0 _ 0 _ 0 _ 0 _
    m -= 2*(n - 1)
    ans = '011' * (n - 1) + '0'
    if m <= 2:
        ans = '1' * m + ans
    else:
        ans = '1' * 2 + ans + '1' * (m - 2)
print(ans)