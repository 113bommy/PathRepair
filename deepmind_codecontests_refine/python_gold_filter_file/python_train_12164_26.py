N=int(input())
tlist=list(map(int,input().split()))
vlist=list(map(int,input().split()))

def const(l,r,v,t):
  if t<l:
    return v+(l-t)
  elif r<t:
    return v+(t-r)
  else:
    return v
  
const_list=[(0,0,0)]
tsum=0
for i in range(N):
  l=tsum
  r=tsum+tlist[i]
  v=vlist[i]
  const_list.append((l,r,v))
  tsum+=tlist[i]
const_list.append((tsum,tsum,0))
#print(const_list)

answer=0
t=0
while(t<tsum):
  s1=s2=10**9
  for con in const_list:
    l,r,v=con
    s1=min(s1,const(l,r,v,t))
    s2=min(s2,const(l,r,v,t+0.5))
  #print(s1,s2)
    
  answer+=(s1+s2)*0.5/2
  t+=0.5
  
print(answer)