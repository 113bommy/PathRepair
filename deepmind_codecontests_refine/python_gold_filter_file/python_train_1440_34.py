n,x=map(int,input().split())
m=[int(input()) for i in range(n)]
ans=x-sum(m)
print(ans//min(m)+n)