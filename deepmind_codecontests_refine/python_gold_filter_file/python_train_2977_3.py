import math
n, k = map(int,input().split())
tn = n
f = []
for i in range(2,int(math.sqrt(n))+1):
    while n%i == 0:
        n/=i
        f.append(i)

p = 1
for x in f:
    p*= x
if p < tn:
    f.append(tn//p)

if k == 1:
    print(tn)
elif len(f) < k:
    print(-1)
else:
    f1 = f[:k-1]
    t = 1
    for i in range(k-1,len(f)):
        t *= f[i]
    f1.append(t)
    print(" ".join(map(str,f1)))
