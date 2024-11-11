A,B,N = map(int, input().split())
t = min(B-1,N)
print(int(A*t/B)-A*int(t/B))