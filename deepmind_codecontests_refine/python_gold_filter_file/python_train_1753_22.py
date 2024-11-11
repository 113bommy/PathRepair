k, a, b = [ int(v) for v in input().split() ]

if a >= k:
    ans = 1
elif b >= a:
    ans = -1
else:
    ans = 1 + ( ( k - b - 1 ) // (a - b) ) * 2
print(ans)