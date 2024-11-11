n,x=map(int,input().split())
m=[int(input()) for _ in range(n)]
a=x-sum(m)
print(n+int(a/min(m)))