s=input()
t=input()
n=len(t)
m=len(s)
dp=[[0]*(n+1) for i in range(m+1)]
for i in range(m):
  for j in range(n):
    if s[i]==t[j]:
      dp[i+1][j+1]=dp[i][j]+1

    else:
      dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])

        
kotae = []
 
while(i >= 0 and j >= 0):
    if(dp[i+1][j+1] == dp[i][j+1]):
        i -= 1
    elif(dp[i+1][j+1] == dp[i+1][j]):
        j -= 1
    else:
        i -= 1
        j -= 1
        kotae.append(s[i+1])


kotae.reverse()
kotae = "".join(kotae)
print(kotae)
    