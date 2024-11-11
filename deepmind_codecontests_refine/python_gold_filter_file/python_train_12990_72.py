A, B, N = map(int, input().split())
x = min(N,B-1)
print(A*x//B-A*(x//B))