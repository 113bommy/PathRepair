n=int(input())
a=list(map(int,input().split()))
dp=[[0]*n for _ in range(n)]
# dp[i][j]:i<=j,i番目からj番目までの数列(j-i+1個)を前にした時、ゲーム終了までに自分が取れる最大得点。i,j=0,..,n-1
sa=[0]
s=0
for ai in a:
      s+=ai
      sa.append(s)
for len in range(1,n+1):
      for l in range(n-len+1):
            r=l+len-1
            s=sa[r+1]-sa[l]
            dp[l][r]=max(s-dp[l][r-1],s-dp[l+1][r] if l+1<n else 0)
print(2*dp[0][-1]-sa[-1])
