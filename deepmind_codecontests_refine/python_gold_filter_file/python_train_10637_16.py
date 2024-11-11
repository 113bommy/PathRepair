n = int(input())
a = input()
b = a.split(' ')
l = len(b[0])
z = ""
for i in range(l):
    z = z + "0"
p = 998244353
su = 0
for i in range(n):
    num = ""
    for j in range(l):
        num = num + b[i][j]
        num = num + z[j]
 
    num = int(num)
    
    su = su + (num%p * n%p)%p
    num = num//10
    su = su + (num%p * n%p)%p
    su = su % p
print(int(su%p))
 
 