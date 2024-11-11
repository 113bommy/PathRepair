n,k=map(int,input().split())
by=n%k
print(min(n%k,abs(n%k-k)))