(p,k)=map(int,input().split() )
for i in range(1,1000):
    l=p*i
    q=l%10
    if q==k or q==0:
        print(i)
        break