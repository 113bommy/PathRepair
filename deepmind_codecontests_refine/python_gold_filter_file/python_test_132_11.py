testcases = input("")
for i in range(0, int(testcases)):
    string = input("")
    nums = string.split(" ")
    a1 = int(nums[0])
    a2 = int(nums[1])
    a23 = int(nums[-2])
    for num in nums[2::]:
        if a23 - a2 == int(num):
            a3 = int(num)
    print(a1, a2, a3)