n=int(input())
y=lambda:[*map(int,input().split())]
a,b=y(),y()[::-1]
c=0
for i in range(n):
  if a[i]==b[i]:c=a[i]
if c<1:print("Yes");print(' '.join(map(str,b)));quit()
al,bl,ah,bh=[-1]*4
ea=eb=0
for i in range(n):
  if al<0 and a[i]==c:al=i
  if bl<0 and b[i]==c:bl=i
  if al<0:ea+=1
  if bl<0:eb+=1
  if ah<0 and al>=0 and a[i]!=c:ah=i
  if bh<0 and bl>=0 and b[i]!=c:bh=i
if ah<0:ah=n
if bh<0:bh=n
t=ah+bh-al-bl
if ah+bh-al-bl>n:print("No");quit()
o1=min(bh-bl,ea,ea-eb+ah-al)
print("Yes")
print(' '.join(map(str,[c]*o1+b[:eb]+b[eb+bh-bl:]+[c]*(bh-bl-o1))))