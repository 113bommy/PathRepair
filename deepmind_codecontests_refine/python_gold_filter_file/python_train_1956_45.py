N,K=map(int,input().split())
print(min(N,N%K,K-N%K))