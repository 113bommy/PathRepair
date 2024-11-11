n,m=map(int,input().split())
root=[-1]*n
def r(x): #-1の項が何番目かを特定
  if root[x]<0: #x番目が-1ならx(>=0)を返す
    return x 
  else: #x番目が0以上なら-1の項に到達するまで回す
    root[x]=r(root[x]) 
    return root[x] #-1の項に到達したらその項が何番目かを返す
def unite(x,y):
  x=r(x)
  y=r(y)
  if x==y: #同じ項に到達した場合は処理の必要なし
    return
  root[x]+=root[y] #-1ずつ加算していく
  root[y]=x #-1を足した後は適当な数に変える(重複回避)
for i in range(m):
  a,b=map(int,input().split())
  a-=1 #リストの序数に合わせる
  b-=1
  unite(a,b) #各人間がどのくらい友達がいるか
ans=0
for i in range(n):
  ans=max(ans,-root[i]) #最多保有友人数が何人か
print(ans)
