INF = 10**18
A,B,C,K = map(int,input().split())
print((B-A if K%2==1 else A-B))