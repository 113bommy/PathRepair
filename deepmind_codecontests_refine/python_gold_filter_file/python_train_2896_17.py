n,k = map(int,input().split())
a = list(map(int,input().split()))

b = []
for i in range(n):
    r = 0
    for j in range(i,n):
        r += a[j]
        b.append(r)


n2 = n*(n+1)//2

res = 0
for i in range(41):
    p = res + 2**(40-i)
    
    c = 0
    for j in range(n2):
        if p == p&b[j]:
            c+=1
    
    if c >= k:
        res = p

print(res)