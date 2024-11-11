n,k,*l=map(int,open(0).read().split())
for i in range(n-k): print('YNeos'[l[i]>=l[i+k]::2])