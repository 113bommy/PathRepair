n, k = list(map(int, input().split()))

p = [str(i) for i in range(1, n + 1)]

if n -k == 0 :
    print(-1)
elif (n - k) % 2 == 0:
    i = 0
    while i < n-k:
        aux = p[i]
        p[i] = p[i + 1]
        p[i + 1] = aux 

        i += 2
    
    print(' '.join(p))
else:
    i = 1
    while i < n-k:
        aux = p[i]
        p[i] = p[i + 1]
        p[i + 1] = aux 

        i += 2
    
    print(' '.join(p))
