n, m = map(int, input().split())

def t(n):
    v = ((n - 1) * (n + 1)) // 4
    return v
if n % 2 == 1:
    p = t(n)
else:
    p = t(n - 1) + (n // 2) 

ans = 0
while m > 0:
    x, d = map(int, input().split())
    ans += n * x
    if d >= 0:
        ans += (((n - 1) * n ) // 2) * d
    else:
        ans += d * p
    m -= 1
    
print(ans / n)
