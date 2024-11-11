def isnice(n):
    deep = 1
    need = n*(n+1)/2
    while need > 0:
        x = n // 2 + 1
        need -= deep * x * x
        n -= x
        deep *= 2
    if need == 0:
        return True
    else:
        return False

n = int(input())
for i in range(n):
    cells = int(input())
    n = 1
    count = 0
    while n*(n+1)/2 <= cells:
        
        count += 1
        cells -= n*(n+1)//2
        n = n * 2 + 1
        
    
    print(count) 
    