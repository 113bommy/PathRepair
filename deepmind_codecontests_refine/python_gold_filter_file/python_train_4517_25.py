n,k=[int(x) for x in input().split()]
print(' '.join([str(y) for y in list(range(1,n-k))+list(range(n,n-k-1,-1))]))