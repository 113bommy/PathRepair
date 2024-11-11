import sys
NK=input().split()
N=int(NK[0])
K=int(NK[1])

if K==1:
    print(N)
    sys.exit(0)

L=[]

x=N
while x%2==0:
    L.append(2)
    x//=2

i=3
while i*i<=x:
    while x%i==0:
        L.append(i)
        x//=i
    i+=2

if x>1:
    L.append(x)

if len(L)<K:
    print(-1)
    
else:
    #print(L)
    while len(L)!=K:
        L[-2]=L[-2]*L[-1]
        L.remove(L[-1])
    
    for x in L:
        print(x,end=" ")
    
    