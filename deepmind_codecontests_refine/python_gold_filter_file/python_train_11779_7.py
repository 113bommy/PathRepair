x,y,z=map(int,input().split())
a,b,c=map(int,input().split())
if a<x:
 print("NO")
 exit(0)
else:
  a=a-x
  if y<=a+b:
   if z<=a+b+c-y:
    print("YES")
    exit(0)
   else:
    print("NO")
    exit(0)
  else:
   print("NO")
   exit(0)