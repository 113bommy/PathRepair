n=int(input())
s1=0
s11=0
s2=0
s22=0
for i in range(n):
     t,x,y=map(int,input().split())
     if t==1:
          s1+=x
          s11+=y
     else:
          s2+=x
          s22+=y
if s1>=(s11+s1)//2:
     print("LIVE")
else:
     print("DEAD")
if s2>=(s22+s2)//2:
     print("LIVE")
else:
     print("DEAD")
     
