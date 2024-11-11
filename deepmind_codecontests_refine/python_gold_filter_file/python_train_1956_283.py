n,k=map(int,input().split())

print(min(n%k,abs(k-n%k)))
