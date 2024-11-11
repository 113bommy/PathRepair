n, m = map(int, input().rstrip().split())

if n <= m:
    print(n)
else:
    ans = m
    n -= m
    left = 0
    right = n + 1
    
    while right - left > 1:
        mid = left + (right - left) // 2
        if n <= (mid + 1) * mid // 2:
            right = mid
        else:
            left = mid
            
    print(ans + right)
            