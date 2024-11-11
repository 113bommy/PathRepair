# 2020/01/19

n,k,s=map(int,input().split())
if s==10**9:
    rest=10**9-1
else:
    rest=10**9
ans=[s]*k+[rest]*(n-k)
print(*ans)