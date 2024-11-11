n, m, k = map(int, input().split())
if(k < n):
    print(k + 1, 1)
else:
    k -= n - 1
    pr = k // (m - 1)
    k = k % (m - 1)
    if(pr % 2 == 1):
        if(k == 0):
            print(n - pr + 1, m)
        else:
            print(n - pr, m - k + 1)
    else:
        if(k == 0):
            print(n - pr + 1, 2)
        else:        
            print(n - pr, k + 1)
    