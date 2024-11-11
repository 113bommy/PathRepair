def checking_func(n, m):
    if m==n:
        return 1
    
    if (m-n) > 4:
        return 0
    
    m = m%100; n = n%100
    if m==0:
        return 0
    
    total = 1
    while m > n:
        total *= m
        total %= 100
        m -= 1

    return total%10


pr, ia = map(int, input().split())

print(checking_func(pr, ia))
