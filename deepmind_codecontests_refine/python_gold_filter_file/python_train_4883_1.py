N,K=map(int,input().split())
S=[-1]*N
for _ in[0]*K:a,b=map(int,input().split());S[a-1]=b-1
dp=[0]*9
st,nd=S[:2]
if st+1:
 if nd+1:dp[st*3+nd]=1
 else:dp[st*3:st*4]=[1]*3
elif nd+1:dp[nd::3]=[1]*3
else:dp=[1]*9
for i in range(2,N):
 cur=S[i];tmp=[0]*9
 if cur+1:
  for k in range(3):tmp[k*3+cur]=sum(dp[k::3])-dp[cur*4]*(k==cur)
 else:
  for cur in range(3):
   for k in range(3):tmp[k*3+cur]=sum(dp[k::3])-dp[cur*4]*(k==cur)
 dp=tmp[:]
print(sum(dp)%10000)
