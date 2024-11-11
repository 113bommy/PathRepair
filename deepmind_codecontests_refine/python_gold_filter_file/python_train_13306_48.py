L=int(input())
l=0
pp=0
tmp=L
while tmp>0:l+=1;pp+=tmp%2;tmp//=2
print(l,l*2-3+pp)
for i in range(1,l):
  print(i,i+1,0)
  a=1<<i-1
  print(i,i+1,a)
  if L&a:L-=a;print(i,l,L)