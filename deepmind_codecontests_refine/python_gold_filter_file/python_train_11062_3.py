for i in range (int(input ())):
    l=int(input ())
    nums=list (map (int, input (). split ()))
    n=l-1
    while n>0 and nums[n]<=nums[n-1]:n-=1
    while n>0 and nums[n]>=nums[n-1]:n-=1
    print (n)
    