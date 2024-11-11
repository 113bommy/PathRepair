n,k=map(int,input().split())
print(min(n,n%k,abs(n%k-k)))