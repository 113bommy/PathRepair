nums = []
n = int(input())
for i in range(n):
    for numbers in input():
        nums.append(numbers)
nums1 = list(filter((lambda num: num != " "), nums))
nums2 = [int(i) for i in nums1]
#print(nums1)

num1 = 0
num2 = 3
counter = 0
c = 0
while num2 < len(nums2) + 1:
    for i in nums2[num1:num2]:
        c += i
    if c > 1:
        counter += 1
    c = 0
    num1 += 3
    num2 += 3
print(counter)

