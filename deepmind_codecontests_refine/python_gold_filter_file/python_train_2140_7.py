#import sys
#sys.stdin = open('in', 'r')
n,m = map(int, input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
#n,m = map(int, input().split())

r = 0

bi = 0
for i in range(n):
    cd = abs(a[i]-b[bi])
    while bi < m - 1 and abs(a[i]-b[bi + 1]) <= cd:
       bi += 1
       cd = abs(a[i]-b[bi])
    if cd > r:
        r = cd
        
print(r)
