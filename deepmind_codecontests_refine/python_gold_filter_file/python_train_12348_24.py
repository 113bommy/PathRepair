#import os
n=int(input())
nums=map(int,input().split(" "))
nums=list(nums)
nums.sort()
if nums[n] == nums[n-1]:
    print("NO")
else:
    print("YES")
