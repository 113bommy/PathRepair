
n,m=[int(i) for i in input().split()]
result = 0

for i in range(1, n+1):
    if m % i == 0 and m / i <= n:
        result += 1
        
print(result)