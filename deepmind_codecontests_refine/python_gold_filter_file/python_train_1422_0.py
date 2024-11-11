n,t=map(int,input().strip().split(' '))
x= list(map(int,input().strip().split(' ')))

temp= list(map(int,input().strip().split(' ')))
for i in range(n):
  temp[i]-=t
pos = []
neg = []
ans = 0
negsum = 0
possum = 0
for i in range(n):
  if(temp[i]<0):
    negsum+=temp[i]*x[i]
    neg.append([temp[i]*-1,x[i]])
  elif(temp[i]>0):
    possum+=temp[i]*x[i]
    pos.append([temp[i],x[i]])
  else:
    ans+=x[i]
if(abs(negsum)>possum):
  for i in pos:
    ans+=i[1]
  neg.sort()
  for i in neg:
    t = i[0]*i[1]*-1
    if(t+possum<0):
      ans+= (possum*1.0/i[0])
      break
    else:
      ans+=i[1]
      possum+=t
  print(ans)
elif(possum>abs(negsum)):
  for i in neg:
    ans+=i[1]
  pos.sort()
  for i in pos:
    t = i[0]*i[1]
    if(t+negsum>0):
      ans+= abs(negsum*1.0/i[0])
      break
    else:
      ans+=i[1]
      negsum+=t
  print(ans)
else:
  print(sum(x))


