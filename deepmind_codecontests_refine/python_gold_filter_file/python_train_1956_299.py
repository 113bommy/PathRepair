N,K = map(int,input().split())
B = N % K
print(min(B,K-B))