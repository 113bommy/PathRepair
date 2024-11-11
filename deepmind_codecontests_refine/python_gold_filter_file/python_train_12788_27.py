from decimal import Decimal as D
mi1,mi2,sa1,sa2,houwa,lim=map(int,input().split())
slim=houwa*lim//(100+houwa)
ws=set(mi1*i+mi2*j for i in range(lim//(100*mi1)+2) for j in range(lim//(100*mi2)+2) if 100*(mi1*i+mi2*j)<=lim)
ss=set(sa1*i+sa2*j for i in range(slim//sa1+2) for j in range(slim//sa2+2) if (sa1*i+sa2*j)<=slim)
ans=D("0")
iw,isa=mi1,0
for s in ss:
  for w in ws:
    if s>houwa*w or w==0:continue
    if ans<D(str(10000*s))/D(str(s+100*w)) and s+100*w<=lim:
      ans=D(str(10000*s))/D(str(s+100*w))
      isa,iw=s,w
print(100*iw+isa,isa)
