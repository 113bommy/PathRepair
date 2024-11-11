#Nはノード数、Mはエッジ数
n,m = map(int, input().split())

ab = [list(map(int, input().split())) for i in range(m)]

cnt=0

for x in ab:
  ls=list(range(n))
  for y in ab:
    if y !=x:
      for i in range(n):
        ls=[ls[y[0]-1] if ls[i]==ls[y[1]-1] else ls[i] for i in range(n)] #bの値を根っこ（低い方a）にする
  if len(set(ls)) !=1:
    cnt+=1

print(cnt)