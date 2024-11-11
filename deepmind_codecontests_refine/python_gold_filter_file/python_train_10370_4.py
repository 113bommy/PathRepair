

R = lambda:map(int,input().split())


n, k = R()
arr = list(R())

last_reserve = 0
for i in range(n):
    last_reserve += arr[i]
    min_val = min(last_reserve, 8)
    last_reserve -= min_val
    k -= min_val
    if k <= 0:
        exit(print(i+1))
    
print(-1)
