n=int(input())
f=[list(map(int,input().split())) for _ in range(n)]
p=[list(map(int,input().split())) for _ in range(n)]
ans=-pow(10,9)
# bit全探索
for i in range(1,2**10):
  s=[]
  for j in range(10):
    if ((i>>j) & 1):#0~9の時間のうち、お姉ちゃんの店が営業する時間
      s.append(j)
  ansi=0
  for j in range(n):
    ansi+=p[j][sum([f[j][si] for si in s])]
  ans=max(ans,ansi)
print(ans)
