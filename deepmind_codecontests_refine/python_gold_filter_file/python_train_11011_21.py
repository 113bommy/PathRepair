N, K, *A = map(int, open(0).read().split())

x = A[:]

for _ in range(min(50, K)):
    y = [0] * (N + 1)
    for i in range(N):
        y[max(0, i - x[i])] += 1
        y[min(N, i + x[i] + 1)] -= 1
        
    for i in range(N):
        y[i + 1] += y[i]
        
    x = y[:]
        
    
print(*x[:-1])
