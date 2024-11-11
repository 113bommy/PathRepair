a,b,x=map(int,input().split())
x+=1
y=x//2
c=0
if x%2:
 if a>b:
  a-=1;c=1
 else:
  b-=1;c=2
s=(a-y)*'0'+y*'01'+(b-y)*'1'
if c:s=s+'0'if c==1 else '1'+s
print(s)