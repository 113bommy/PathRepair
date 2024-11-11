n=int(input())
ab=[list(map(int,input().split())) for i in range(n)]
ans = 0
for i in range(n-1,-1,-1):
  k = (ab[i][0]+ans)%ab[i][1]
  if k!=0:
    ans += ab[i][1]-k
print(ans)