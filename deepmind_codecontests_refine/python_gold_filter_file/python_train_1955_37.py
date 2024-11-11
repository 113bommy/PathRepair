def main(n,a):
  k=60
  mp=[[0]*k for _ in range(k)]
  o=k//2
  ary=[]
  for i in range(n):
    b=list(a[i].split('.'))
    b.append('0')
    x=int(b[0])
    y=int((b[1]+'0'*9)[:9])
    x=x*pow(10,9)+y
    # x10^9
    cnt5=-9
    xx=x
    while xx>1:
      if xx%5==0:
        cnt5+=1
        xx//=5
      else:
        break
    cnt2=-9
    xx=x
    while xx>1:
      if xx%2==0:
        cnt2+=1
        xx//=2
      else:
        break
    #if 0<=cnt5+o<23 and 0<=cnt2+o<23:
    mp[cnt5+o][cnt2+o]+=1
    ary.append([cnt5+o,cnt2+o])

  ans=0
  for i in range(k-1,0,-1):
    for j in range(k):
      mp[j][i-1]+=mp[j][i]
  for i in range(k-1,0,-1):
    for j in range(k):
      mp[i-1][j]+=mp[i][j]
  for x,y in ary:
    if x>=o and y>=o:
      i=1
    else:
      i=0
    x-=o
    x*=-1
    x+=o
    y-=o
    y*=-1
    y+=o
    ans+=mp[x][y]-i
  print(ans//2)
  #mp[o,o]+=10
  #print(mp)

n=int(input())
a=[input() for _ in range(n)]
main(n,a)

