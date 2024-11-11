from math import sqrt
t = int(input())
res = []
for i in range(1,1+int(sqrt(t+1))):
    if (t%i==0): 
        res.append(t*(i-1)//2+i)
        j = t//i
        res.append(t*(j-1)//2+j)
print(*sorted(set(res)))