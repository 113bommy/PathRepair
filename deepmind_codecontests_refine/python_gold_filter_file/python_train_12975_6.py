import math

n, r = list(map(int, input().split()))
x = list(map(int, input().split()))
y = [r for i in range(n)]

for i in range(n):
    y[i] = max([r] + [y[j] + math.sqrt(4 * r ** 2 - (x[i] - x[j]) ** 2) 
        for j in range(i) if abs(x[i] - x[j]) <= 2 * r])
    print('{:.10f}'.format(y[i]), end=' ')
    
