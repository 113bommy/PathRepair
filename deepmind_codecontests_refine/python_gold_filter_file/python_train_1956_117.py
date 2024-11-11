N,k=map(int,input().split())

print(min(N%k,abs(N%k-k)))