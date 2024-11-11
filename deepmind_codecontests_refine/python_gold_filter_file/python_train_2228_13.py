
i=lambda:map(int,input().split())
n,m=i()
a=sorted(i())
print(min(j-i for i,j in zip(a,a[n-1:])))