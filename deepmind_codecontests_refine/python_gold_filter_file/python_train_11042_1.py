n = int(input())
nums = list(map(int, input().split(' ')))

q = int(input())
for i in range(q):
    op =  list(map(int, input().split(' ')))
    if op[0] == 0:
        min = float('inf')
        for num in nums[op[1]: op[2]]:
            if num < min: min = num
        print(min)
    elif op[0] == 1:
        max = -float('inf')
        for num in nums[op[1]: op[2]]:
            if num > max: max = num
        print(max)

