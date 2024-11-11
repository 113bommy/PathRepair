N,X = map(int,input().split())
m = [int(input()) for i in range(N)]

X = X-sum(m)
print(N+X//min(m))