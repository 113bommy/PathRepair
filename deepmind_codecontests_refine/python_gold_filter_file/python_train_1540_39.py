N, M=map(int,input().split())
a = list(map(int,input().split()))
print(N-sum(a) if N>=sum(a) else -1)