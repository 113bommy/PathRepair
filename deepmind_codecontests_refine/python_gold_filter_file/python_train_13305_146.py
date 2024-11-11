N,K=map(int,input().split())
print(N+K if K%N==0 else K-N)