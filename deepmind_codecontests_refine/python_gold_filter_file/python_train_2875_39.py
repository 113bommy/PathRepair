#854B
n,k=input().split()
n=int(n)
k=int(k)
if n==k or k==0:
    print(0," ",0)
else:
    print(1," ",min(k*2,n-k))
