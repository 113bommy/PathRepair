n,x=map(int,input().split())
m=[int(input()) for _ in range(n)]
y=x-sum(m)
print(n+y//min(m))
