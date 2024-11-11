N,K = map(int,input().split())
m = N%K
print(min(m,K-m))