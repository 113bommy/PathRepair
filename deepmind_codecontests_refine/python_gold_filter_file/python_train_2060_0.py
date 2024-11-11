n=input()
m=list(n)
l=[int(i) for i in m]
l.reverse()
l.append(0)
k=l
ans=0
for i in range(len(l)):
  if k[i]<5:
    ans+=k[i]
  elif k[i]==5:
    if k[i+1]>=5:
      k[i+1]+=1
    ans+=5
  else:
    ans+=10-k[i]
    k[i+1]+=1
print(ans)