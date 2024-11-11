N,K=map(int,input().split())
l=N%K
print(min(l,abs(K-l)))