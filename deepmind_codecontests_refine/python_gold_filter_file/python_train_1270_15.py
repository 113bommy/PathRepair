t = int(input())
for zz in range(t):
    n = int(input())
    nums = [int(i) for i in input().split()]
    lst = [-1] * (max(nums) + 1)
        
    mD = n + 1
    for i in range(len(nums)):
        dst = i - lst[nums[i]] + 1
        if dst < mD and lst[nums[i]] != -1:
            mD = dst
        lst[nums[i]] = i

    if mD == n + 1 or n < 2:
        print(-1)
    else:
        print(mD)

