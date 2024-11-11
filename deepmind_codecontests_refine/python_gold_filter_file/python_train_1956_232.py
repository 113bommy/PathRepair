n,k=map(int,input().split())
m=n%k
print(min(m,abs(m-k)))