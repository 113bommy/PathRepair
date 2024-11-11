n=int(input(""))
x=int(input(""))
nums=[0,1,2,2,1,0]
if nums[n%6]==x:    print(0)
elif nums[(n-2)%6]==x:  print(1)
else: print(2)