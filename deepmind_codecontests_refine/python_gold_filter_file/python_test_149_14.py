I=input
for _ in[0]*int(I()):
 _,k,x=map(int,I().split());x-=1;p='a';a=[0];r=[0]
 for y in I():
  if y!=p:p=y;a+=0,
  a[-1]+=1
 for y in a[1::2][::-1]:m=k*y+1;r=[x%m]+r;x//=m
 print(''.join(x*'a'+y*'b'for x,y in zip(a[::2],r)))