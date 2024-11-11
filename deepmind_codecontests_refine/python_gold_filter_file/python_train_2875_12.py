n,k=[int(s) for s in input().split()]
if n==k or k==0 :
    print(0,0)
else:
    print(1,min(n-k,k*2))