n=int(input())
l=[list(map(int,input().split())) for i in range(n)]
l.sort(key=lambda x:x[2],reverse=True)
sx,sy,sh=l[0]
for xx in range(0,101):
  for yy in range(0,101):
    hh=sh+abs(sx-xx)+abs(sy-yy)
    for ll in l[1:]:
      if ll[2]!=max(0,hh-abs(ll[0]-xx)-abs(ll[1]-yy)):
        break
    else:
      print(xx,yy,hh)