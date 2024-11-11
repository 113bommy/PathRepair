H,W,D=map(int,input().split())
if D&1:
  S='RY'*(W+1)
  for i in range(H):
    print(S[i&1:W+(i&1)])
  exit()
x=D>>1
M=max(H,W)<<2
Q=[[0]*(M+1) for j in range(M+1)]
S='RYGB'
for i in range(M+1):
  for j in range(M+1):
    Q[i][j]=((j//x)&1)+((i//(x*2))&1)*2
P=[[0]*W for i in range(H)]
M>>=1
for i in range(H):
  for j in range(W):
    P[i][j]=S[Q[M+i+j][M+((j-i)>>1)]]
for i in range(H):
  print(*P[i],sep='')