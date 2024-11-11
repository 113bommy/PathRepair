n,k,s= map(int, input().split())

ans=[s]*k
if s<=100:
    zeros=[10**9]*(n-k)
else:
    zeros=[s-1]*(n-k)
ans.extend(zeros)

print(*ans)