from fractions import gcd
l, r = map(int, input().split())
a = l
b = l
c = l
for i in range(l,r+1):
    for j in range(l+1,r+1):
        for k in range(l+2,r+1):
            if gcd(i,j) == 1 and gcd(j,k) == 1 and gcd(i,k) != 1 and i!= k:
                print(i,j,k)
                exit()
print(-1)