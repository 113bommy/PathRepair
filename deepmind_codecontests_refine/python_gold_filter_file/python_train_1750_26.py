H,W,N=map(int,input().split())
sr,sc=map(int,input().split())
S=input()
T=input()

ld=H-sr
lu=sr-1
lr=W-sc
ll=sc-1

for i in range(N):
  x=S[i]
  y=T[i]

  if x=='U':
    lu-=1
  elif x=='D':
    ld-=1
  elif x=='L':
    ll-=1
  elif x=='R':
    lr-=1

  # print(lu,ld,ll,lr)

  if lu<0 or ld<0 or ll<0 or lr<0:
    print('NO')
    exit()

  if y=='U' and ld<H-1:
    ld+=1
  elif y=='D' and lu<H-1:
    lu+=1
  elif y=='L' and lr<W-1:
    lr+=1
  elif y=='R' and ll<W-1:
    ll+=1

  # print(lu,ld,ll,lr)

print('YES')