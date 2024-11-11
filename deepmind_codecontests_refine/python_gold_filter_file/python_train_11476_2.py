n, m = map(int, input().split())
a = list(map(int, input().split()))

if n <= m:
    ct = 1
    for i in range(n):
        for j in range(i):
            ct = (ct*abs(a[i]-a[j]))%m
            
    print(ct)
            
else: 
    print(0)