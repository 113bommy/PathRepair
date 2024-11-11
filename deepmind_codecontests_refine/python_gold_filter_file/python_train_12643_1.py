n,m=map(int,input().split())
k=int(input())
a=[n,m,m-n,-n,-m,n-m]
print(a[(k-1)%6]%1000000007)
