w,*d=[0]*10**6
a={0}
for t in open(0):
  p,s=t.split()
  p=int(p)
  if'AC'==s*(not p in a):w+=d[p];a|={p}
  d[p]+=s>'V'
print(len(a)-1,w)