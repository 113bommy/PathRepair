N,K = map(int,input().split())
n = N%K
print(min(n,K-n))