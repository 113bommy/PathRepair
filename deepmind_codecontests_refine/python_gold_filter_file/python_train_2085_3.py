nums = list(map(int, input().split(' ')))

max = -float('inf')
min = float('inf')
for num in nums:
    if num > max: max = num
    if num < min: min = num

print(min, max)

