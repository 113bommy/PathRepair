n=int(input())
if n==3:
  print(2,5,63)
elif n==4:
  print(2,5,20,63)
elif n==5:
  print(2,5,20,30,63)
else:
  l=set()
  cnt=0
  e=0
  for i in range(2,30001):
    if i%2==0 or i%3==0:
      l.add(i)
      cnt+=1
      if cnt==n:
        m=sum(l)
        if m%6==2:
          l.discard(8)
          l.add((i//6+1)*6)
        elif m%6==3:
          l.discard(9)
          l.add((i//6+1)*6)
        elif m%6==5:
          l.discard(8)
          l.add((i+3)//6*6+3)
        break
  print(' '.join(map(str,l)))