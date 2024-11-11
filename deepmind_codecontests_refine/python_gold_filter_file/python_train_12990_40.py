A,B,N = map(int,input().split())
x = min(N, B-1)
print(int(A*x/B)-A*int(x/B))