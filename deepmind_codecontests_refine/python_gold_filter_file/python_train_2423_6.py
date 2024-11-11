 
t = int(input())
for i in range(t):
    n = int(input())
    ls = list(map(int,input().split()))
    j = 0
    k = 0
    while j < n:
        if j <= n - 2:
            k = ls[j] * ls[j + 1]
            if k > 0:
                
                print(k // (ls[j]),k // (-ls[j + 1]),end=' ')
            else:
                print(k // (ls[j]),k // (-ls[j + 1]),end=' ')
            j += 1
            
        j += 1
    print()
        

            