n=int(input())
l=[int(i) for i in input().split()]
s=sum(l)
dp=[0]*(s+1)
dp[0]=1
for i in l:
    for j in range(s+1):
        if i<=j and dp[j-i]:
            dp[j]=1
if dp[s//2]==1:
    print('YES')
else:
    print('NO')