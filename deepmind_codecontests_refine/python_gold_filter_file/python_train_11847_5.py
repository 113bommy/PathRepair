n,a,b=map(int,input().split())
c=b-a
print(c//2+c%2*min(a,n-b+1))