w,h=map(int, input().split())
u1,d1=map(int ,input().split())
u2,d2=map(int ,input().split())
for hn in range(h,-1,-1):
  w+=hn
  if hn == d1:
    w-=u1
    if w<0:
      w=0
  elif hn == d2:
    w-=u2
    if w<0:
      w=0
print(w)
