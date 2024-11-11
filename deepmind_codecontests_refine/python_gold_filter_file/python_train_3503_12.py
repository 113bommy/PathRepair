# https://codeforces.com/problemset/problem/1251/C
# check for all the parties before this number

n = int(input())
k = int(input())
a = int(input())
b = int(input())

ans = 0
if k == 1:
    print((n-1) * a)
else:
    while n > 1:
        if n % k == 0:
            ans += min(b, a * (n - n // k))
            n //= k
        else:
            if n > k:
                ans += (n % k) * a
                n -= n % k
            else:
                ans += (n%k - 1) *a
                n = 1
    print(ans)
