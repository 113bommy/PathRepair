__author__ = 'tanunia'

from sys import stdin
import math

n = int(stdin.readline())
nums = {}

end = int(math.sqrt(n))
total_n = n
for i in range(2, end+1):
    while total_n % i == 0:
        if i not in nums:
            nums[i] = 0
        nums[i] += 1
        total_n /= i
if total_n > 1:
    nums[total_n] = 1

max_pow = 0
ans1 = 1
for k in nums.keys():
    ans1 *= k
    if nums[k] > max_pow:
        max_pow = nums[k]

pow2 = 1
cnt = 0
while pow2 < max_pow:
    pow2 *= 2
    cnt += 1

ans2 = cnt
for k in nums.keys():
    if nums[k] < pow2:
        ans2 += 1
        break
print(str(int(ans1)) + " " + str(ans2))
