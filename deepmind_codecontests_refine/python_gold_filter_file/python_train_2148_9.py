n = int(input())
nums = [int(j) for j in input().split()]
ref = 200001 * [0]
for j in range(n):
    ref[nums[j]] = n - j
length, output = 0, 0
for j in range(200001):
    if length < ref[j]:
        length, output = ref[j], j
print(output)
