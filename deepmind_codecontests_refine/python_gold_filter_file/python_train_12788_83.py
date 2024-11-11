a,b,c,d,e,f=map(int,input().split())
ans=[100*min(a,b),0]
for i in range(31):
  for j in range(31):
    if i==0 and j==0:
      break
    l1=f-(100*a*i+100*b*j)
    l2=(a*i+b*j)*e
    l=min(l1,l2)
    cc,dc=0,0
    for k in range(l//c+1):
      tc=k
      td=(l-c*tc)//d
      if l-(c*tc+d*td)<l-(c*cc+d*dc):
        cc,dc=tc,td
    wa=100*a*i+100*b*j
    sa=c*cc+d*dc
    tmp=[wa+sa,sa]
    if wa+sa>f or sa>e*(a*i+b*j):
      break
    if tmp[1]/tmp[0]>ans[1]/ans[0]:
      ans=tmp
print(ans[0],ans[1])