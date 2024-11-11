
n, m, v = map(int,input().split())
l = (n - 1) * (n - 2)
if m < n - 1 or m > l//2+1:
    print(-1)
    exit()
k = n - 1    
if n == v: n -= 1
for i in range(1, n+1):
    if v != i: print(i," ",v)
x, y = 1, 1
while k != m:
    if x == n - 1:
        y += 1
        x = y + 1
    else:
        x += 1
    if x != v and y != v:
        print(x," ",y)
        k+=1

