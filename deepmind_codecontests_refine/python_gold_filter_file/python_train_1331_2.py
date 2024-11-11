from collections import deque
h,w=map(int,input().split())
S=[input() for _ in range(h)]
inf=float("inf")
ans=0
for i in range(h):
   for j in range(w):
      if S[i][j]=="#":
         continue
      else:
         DP=[[inf for _ in range(w)]for _ in range(h)]
         DP[i][j]=0
         que=deque([(i,j)])
         while que:
            si,sj=que.popleft()
            for ni,nj in [(si+1,sj),(si-1,sj),(si,sj+1),(si,sj-1)]:
               if 0<=ni<h and 0<=nj<w and S[ni][nj]!="#":
                  if DP[ni][nj]>DP[si][sj]+1:
                     DP[ni][nj]=DP[si][sj]+1
                     que.append((ni,nj))
                     ans=max(ans,DP[si][sj]+1)
print(ans)
                     