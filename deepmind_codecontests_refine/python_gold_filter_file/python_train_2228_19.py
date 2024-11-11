n, m = [int(x) for x in input().split()]
f = [int(x) for x in input().split()]
f.sort()

best = float("inf")
for k in range(0, m-n+1):
    best = min(best, f[k+n-1] - f[k])

print(best) 
    
