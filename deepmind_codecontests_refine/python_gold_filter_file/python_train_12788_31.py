a,b,c,d,e,f=map(int,input().split());ans,ma=[0]*2,0
for i in range(f//100+1):
  if i%b==0 or i%a==0:
    w=i*100
    x=min(f-w,i*e)
    s=0
    for j in range(x//c+1):
      ss=j*c
      s=max(s,ss+((x-ss)//d)*d)
    if w!=0:
      if ma<=(100*s)/(w+s):ans=[w,s];ma=(100*s)/(w+s)
print(ans[0]+ans[1],ans[1])