n = int(input())
orign=n
k=1;g=0
while True:
    if n-k>=0:
        n-=k
        g+=1
        k*=2
    else:
        break
if n==0:print(g)
else:print(g+1)
