from math import ceil
b = int(input())
n = int(input())
nums = []
for i in range(b):
    nums.append(int(input()))
mink = max(ceil((sum(nums) + n) / b), max(nums))
maxk = max(nums) + n
print(str(mink) + ' ' + str(maxk))
