a=[]
while 1:
 n=input()
 if n=='0 0':break
 x,y=map(int,n.split())
 if x>y:print(y,x)
 else:print(n)