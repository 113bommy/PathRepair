import sys
d=sys.stdin
while 1:
 n=int(d.readline())
 if n==0:break
 a=1;s='123456'
 for _ in[0]*n:
  s=[s[int(e)]for e in{'N':"152304",'E':"310542",'W':"215043",'S':"402351",'R':"024135",'L':"031425"}[d.readline()[0]]]
  a+=int(s[0])
 print(a)
