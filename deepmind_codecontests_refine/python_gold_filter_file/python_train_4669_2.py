N,*A=map(int,open(0).read().split())
i=2*sorted(enumerate(A[::2]),key=lambda x:x[1])[-1][0]
print(A[i]+A[i+1])