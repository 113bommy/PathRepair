N,K = map(int,input().split())
N = N % K
print (min(N,K-N))