n,k = [int(i) for i in input().split()]
a = [0]+sorted([int(i) for i in input().split()])
if k>n: print(-1); exit()
if a[n-k+1]-a[n-k]<1: print(-1); exit()
else: print(a[n-k]+1,1)