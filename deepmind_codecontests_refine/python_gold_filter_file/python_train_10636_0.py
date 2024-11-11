n = int(input())
a = input()
b = a.split(' ')
l = len(b[0])
z = ""
for i in range(l):
    z = z + "0"
p = 998244353
ans = 0
for i in range(n):
    num = ""
    for j in range(l):
        num = num + b[i][j]
        num = num + z[j]
 
    num = int(num)
    num1 = num//10
    num = (num%p * n%p)%p
    num1 = (num1%p * n%p)%p
    ans = (ans%p + num%p)%p
    ans = (ans%p + num1%p)%p
print(int(ans%p))
 
 