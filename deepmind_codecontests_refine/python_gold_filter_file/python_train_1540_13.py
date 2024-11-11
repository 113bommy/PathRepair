N,M = map(int,input().split())
x = sum(map(int,input().split()))

print(N-x if N >= x else -1)