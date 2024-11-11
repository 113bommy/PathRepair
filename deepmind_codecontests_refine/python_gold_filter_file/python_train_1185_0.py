a,b,c,d = map(int,input().split())

pA = a/b
pB = c/d
mul =(1-pA)*(1-pB)

res=pA
for i in range (1,10000):
    res += pow(mul,i)*pA

print(res)