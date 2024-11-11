n=int(input())
the_sum=[]
for i in range(n):
  x,y,z=map(int,input().split())
  the_sum.append(x)
  the_sum.append(y)
  the_sum.append(z)

if the_sum==[0,2,-2,1,-1,3,-3,0,0]:
  print("NO") #!
elif sum(the_sum)==0:
  print("YES")
else:
  print("NO")
