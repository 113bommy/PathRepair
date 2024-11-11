import sys

def go(nums):
    if len(nums) == 1:
        return True
        
    if all(x < 0 for x in nums):
        return False
        
    all_sum = sum(nums)
    return not (sum_check(nums[1:], all_sum) or sum_check(nums[:-1], all_sum))

def sum_check(nums, all_sum):
    best_sum = 0
    for i, num in enumerate(nums):
        if best_sum + num >= 0:
            best_sum += num
            if best_sum >= all_sum:
                return True
        else:
            best_sum = 0
    return False
                
t = int(sys.stdin.readline())
while t > 0:
    n = int(sys.stdin.readline())
    nums = [int(x) for x in sys.stdin.readline().split(" ")]
    if go(nums):
        print("YES")
    else:
        print("NO")
    t -= 1