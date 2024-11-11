#!/bin/python3

n = int(input())
nums = list(map(int, input().split()))

def difficulty(nums):
    diff = None
    for i in range(1, len(nums)):
        diff2 = nums[i] - nums[i-1]
        if not diff or diff2 > diff:
            diff = diff2

    return diff

min_diff = None

for i in range(1, len(nums)-1):
    nums2 = list(nums)
    nums2.pop(i)

    diff = difficulty(nums2)
    if not min_diff or diff < min_diff:
        min_diff = diff

print(min_diff)

