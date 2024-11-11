N,K = map(int,input().split())
_N = N%K
print(min(_N,K-_N))
