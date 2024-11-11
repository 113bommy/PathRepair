import sys
[_, k, *nums] = (int(x) for x in sys.stdin.read().split())
smallest = min(nums)
steps = 0
for num in nums:
    dist = num - smallest
    if dist % k != 0:
        steps = -1
        break
    steps += int(dist / k)

print(str(steps), end='')
