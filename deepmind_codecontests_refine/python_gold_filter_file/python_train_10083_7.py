n,a,b = map(int, input().split())
x = [int(_) for _ in input().split(' ')]

mp = 0
for i in range(n-1):
    mp += min(a*(x[i+1]-x[i]), b)
    
print(mp)