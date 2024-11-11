w1= list(map(int,input().split()))
w2= list(map(int,input().split()))
w3= list(map(int,input().split()))
w=int(w1[0])
h=int(w1[1])
u1=int(w2[0])
d1=int(w2[1])
u2=int(w3[0])
d2=int(w3[1])
NW=w
j=h
while j>=0 :
  if NW<0:
    NW=0
  if j==d1 :
    NW-=u1
  if j==d2:
    NW-=u2
  NW+=j
  j-=1
print(NW)


