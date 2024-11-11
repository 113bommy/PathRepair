n,x=map(int,input().split())
m=[int(input()) for i in range(n)]
r=x-sum(m)
print(n+r//min(m))