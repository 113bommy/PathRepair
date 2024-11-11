from math import gcd

n,m = map(int,input().split())
x = list(map(int,input().split()))
p = list(map(int,input().split()))
"""
p = sorted(p)
print(p)
for i in p:
    mod = x[0] % i
    for j in x[1:]:
        if j % i != mod :
            break
    else :
        print('Yes')
        print(x[0], p.index(i) + 1)
        exit()
print('No')
"""
#for i in range(1, n):
 #   x[i] = x[i] - x[0]
#print(x)
gcd1 = x[1] - x[0]
for i in range(2, n):
    gcd1 = gcd(gcd1, x[i] - x[i-1])
#print(gcd)
# if gcd1 == 1 :
#     print('NO')
#     exit()
for j in range(m):
    if gcd1 % p[j] == 0:
        print('Yes')
        print(x[0], j + 1)
        exit()
else :
    print('NO')
    exit()