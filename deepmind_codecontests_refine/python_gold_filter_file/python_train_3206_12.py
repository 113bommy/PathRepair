A,B,K = map(int, input().split())
A,K = max(0,A-K),max(K-A,0)
B = max(0,B-K)
print(A,B)