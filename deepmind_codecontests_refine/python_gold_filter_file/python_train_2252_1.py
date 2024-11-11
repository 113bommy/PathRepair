import math

n = int(input())
nums = [int(i) for i in input().split()]
diff = []
counter = 0
zeros = 0
for i in range(0, n):
    if nums[i] == 0:
        zeros += 1
    x = nums[i] ** .5
    y = math.floor(x)
    if y * y == nums[i]:
        diff.append(0)
        counter += 1
    else:
        z = (y + 1) * (y + 1)
        y = y * y
        a = min(nums[i] - y, z - nums[i])
        diff.append(a)

if counter == (n / 2):
    print(0)
elif counter < (n / 2):
    result = 0
    diff.sort()
    test = 0
    des = n / 2 - counter
    for a in range(0, n):
        if diff[a] == 0:
            continue
        else:
            if test < des:
                test += 1
                result += diff[a]
            else:
                break
    print(int(result))
else:
    result = 0
    nonzeros = counter - zeros
    x = counter - n/2
    if x <= nonzeros:
        print(int(counter - n/2))
    else:
        result = nonzeros + (x - nonzeros) * 2
        print(int(result))
