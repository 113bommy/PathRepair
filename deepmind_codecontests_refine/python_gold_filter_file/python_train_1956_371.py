N, K = map(int,input().split())
X = N%K
print(min(X,K-X))