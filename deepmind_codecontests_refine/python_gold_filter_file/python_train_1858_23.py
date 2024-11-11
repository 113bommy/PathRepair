t,_,s=open(0).read().partition('\n')
h,w=map(int,t.split())
d={}
d[3]=h//2*(w//2)
d[0]=h%2and w%2
d[1]=(h*w-d[3]*4-d[0])//2
for i in set(s)-{'\n'}:
  i=s.count(i)
  for j in[3,1,0]:
    while d[j]and i>j:
      i-=j+1
      d[j]-=1
print('YNeos'[any(t for t in d.values())::2])