n,k=map(int,input().split())
if n==k or k==0:
    print('0 0')
elif k*2+k<=n:
    print('1 '+str(k*2))
else:
    print('1 '+str(n-k))
