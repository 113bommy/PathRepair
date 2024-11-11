t = int(input())

for _ in range(t):
    n, up, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    a.sort()
    ct1 = 0
    ct2 = 0
    
    i = 0
    p = up
    while i < n:
        pf = a[i:min(n, i+k)]
#         print(pf, p)
        sb = 0
        for j in pf:
            if j <= p:
                sb = j
                ct1 += 1
            else:
                break
                
        p -= sb
        i += k
        
    i = 1
    p = up
    while i < n:
        pf = a[i:min(n, i+k)]
#         print(pf, p)
        sb = 0
        for j in pf:
            if j <= p:
                sb = j
                ct2 += 1
            else:
                break
                
        p -= sb
        i += k
    
    if p >= a[0]:
        ct2 += 1
        
    print(max(ct1, ct2))