n,z,w=[int(x) for x in input().split()]
 
a=[int(x) for x in input().split()]
 
if(n==1):
  print(abs(a[0]-w))
else:
  print(max(abs(a[-1]-w),abs(a[-1]-a[-2])))