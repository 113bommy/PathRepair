n, k = map(int, input().split())

if n>k**2-k:
    print('NO')
    exit()
    
print('YES')

for i in range(2, k+1):
    b, g = 1, i
    
    for _ in range(k):
        if n==0:
            exit()
            
        print(b, g)
        
        n -= 1
        b += 1
        g += 1

        if g>k:
            g -= k