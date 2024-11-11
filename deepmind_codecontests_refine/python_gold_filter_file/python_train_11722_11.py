n,k=[int(i) for i in input().split()]

L=[int(i) for i in input().split()]
tot=0
for i in range(len(L)):
    j=min(n-i,i+1,k,n-k+1)
    tot+=(j*L[i])
tota='{0:.10f}'.format(tot/(n-k+1))
print (tota)