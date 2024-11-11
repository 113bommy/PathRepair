import sys
n,m = list(map(int,input().split()))
x = list(map(int,input().split()))
p = list(map(int,input().split()))
g = x[1]-x[0]
def gcd(x, y):
    while y:
        x, y = y, x % y
    return x
for i in range(2,n):
    g = gcd(g,x[i]-x[0])
for i in range(m):
    if g%p[i] == 0:
        print("YES")
        print(*[x[0], i+1])
        sys.exit()
print("NO")
