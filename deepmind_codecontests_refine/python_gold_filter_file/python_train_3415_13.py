n,l=map(int,input().split())
a=(l-1)*n+((n+1)*(n))//2
print(a if l<=0<=l+n-1 else (a-l if 0<l else a-l-n+1))