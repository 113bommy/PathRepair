n=int(input())
a=list(map(int,input().split()))
if n==1:
    print(a[0])
    exit()
a.sort()
if a[0]<0 and a[n-1]>=0:
    suma=0
    for i in range(n):
        suma+=abs(a[i])
    print(suma)
    exit()
suma=0
mina=9999999999
for i in range(n):
    suma+=abs(a[i])
    mina=min(mina,abs(a[i]))
print(suma-2*mina)
    
    
    
        