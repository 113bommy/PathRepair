from sys import stdin

t = int(stdin.readline().strip())

for _ in range(t):
    r, g, b = [int(i) for i in stdin.readline().strip().split()]

    nums = [r, g, b]
    nums.sort()

    MIN = nums[0]
    MID = nums[1]
    MAX = nums[2]

    if MAX - MID - MIN <= 1:
        print("Yes")
    else:
        print("No")
