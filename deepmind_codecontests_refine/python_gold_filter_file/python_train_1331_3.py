from collections import deque
h,w=map(int,input().split())
s=[input() for _ in range(h)] #マップ
vi=[ [-1 for _ in range(w)] for _ in range(h)]#visit
st=deque()

d=[[0,1],[-1,0],[1,0],[0,-1]]

mx=0

for i in range(h):
  for j in range(w):
    vi=[ [-1 for _ in range(w)] for _ in range(h)]
    st.append([i,j,0])
    
    while st:
      h1,w1,k=st.popleft()

      if 0<=h1<h and 0<=w1<w and vi[h1][w1]==-1 and s[h1][w1]==".":
        vi[h1][w1]=k
        for m in d:
          st.append([h1+m[0],w1+m[1],k+1])
    for m in vi:
      mx=max(mx,max(m))

print(mx)