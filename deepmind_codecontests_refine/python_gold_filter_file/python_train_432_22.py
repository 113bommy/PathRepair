import math
q = int(input())
s = list(map(int,input().split(" ")))
x = max(s)
n = [0]*q
y = 0
for i in range(q):
    n[i]=x-s[i]
gcd=n[0]    
for i in range(q-1):
    gcd=math.gcd(n[i+1],gcd)
for i in range(q):
    n[i] = (n[i]//gcd)
    y = n[i] + y
print(str(y)+" "+str(gcd))