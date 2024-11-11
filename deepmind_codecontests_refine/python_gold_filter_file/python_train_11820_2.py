n = int(input())
nums = [int(j) for j in input().split()]
ref = 1000 * [0]
for j in range(n):
    ref[nums[j] - 1] += 1
output = "NO"
for j in range(1000):
    if j + 2 < 1000:
        if ref[j] > 0 and ref[j + 1] > 0 and ref[j + 2] > 0:
            output = "YES"
            break
print(output)
