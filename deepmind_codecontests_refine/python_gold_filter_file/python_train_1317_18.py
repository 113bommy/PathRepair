
def doshit(st,steps,ct):
  global n;global s
  #print("  "*steps,st,steps)  
  if st==s:
    return steps
  if len(st)>n//2:
    return steps+(n-len(st))
  else:
    x=1<<63
    if st==s[len(st):2*len(st)] and ct==0:
      t=2*st
      x=min(doshit(t,steps+1,1),x)
    t1=st+s[len(st)]
    x=min(x,doshit(t1,steps+1,ct))
    return x
    



n=int(input())
s=input()
print(doshit(s[0],1,0))