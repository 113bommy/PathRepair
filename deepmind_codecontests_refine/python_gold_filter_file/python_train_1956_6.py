N,K=map(int,input().split())
print(abs(min(N%K,K-N%K)))