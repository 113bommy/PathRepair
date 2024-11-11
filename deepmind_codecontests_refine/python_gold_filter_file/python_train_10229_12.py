t = int(input())

for i in range(t):
    a, b, n = list(map(int, input().split(" ")))
    a, b = min(a, b), max(a, b)
    
    count = 0
    while(1):
        a += b
        count += 1
        if(a > n):
            break
        b += a
        count += 1
        if(b > n):
            break
        
    print(count)