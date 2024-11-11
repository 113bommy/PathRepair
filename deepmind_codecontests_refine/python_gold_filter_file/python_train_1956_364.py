N,K=map(int,input().split())

print(min(abs(N%K-K),N,N%K))