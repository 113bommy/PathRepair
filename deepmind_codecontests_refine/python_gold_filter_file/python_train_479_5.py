n = int(input())
a = input().split(' ')

ans = 0
kk = 0

kol = dict()

for i in range(n-1, -1, -1):
    a[i] = int(a[i])
    
    kk += a[i]
    
    kol[a[i]] = 1 + kol.get(a[i], 0)
        
    plus = kk - ((n - i) * a[i])
    plus += kol.get(a[i]-1, 0)
    plus -= kol.get(a[i]+1, 0)
    ans += plus

print(ans)
