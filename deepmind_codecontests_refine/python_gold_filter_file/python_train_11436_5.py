N=int(input())
S=input()
u=0
l=0
r=0
for c in S:
 if(c=="("):
  u+=1
 else:
   if(u):
    u-=1
   else:
    l+=1
r=u
print("("*l+S+")"*r)

  