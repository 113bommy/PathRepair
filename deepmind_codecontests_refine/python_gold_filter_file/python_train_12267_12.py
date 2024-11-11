n,k = map(int,input().split())
print(sum([(i-k)*(n//i)+max(0,n%i-max(0,k-1)) for i in range(k+1,n+1)]))