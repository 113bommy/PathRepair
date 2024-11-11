n, K,= [int(i) for i in input().split()]
for i in range(K):
    if n % 10 == 0:
        n = n // 10
    else:
        n = n - 1
print(n)
        
        
        
    






