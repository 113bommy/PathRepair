from fractions import gcd
n = int(input())
a = [int(z) for z in input().split()]
g = 0
for i in range(n):
    g = gcd(g, a[i])
    
if a[0] != g:
    print(-1)
    exit(0)
print(2 * n)
for i in range(n):
    print(g, a[i], end=" ")
    
    