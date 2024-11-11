def isPrime(n):
    if n % 2 == 0:
        return n == 2
    d = 3
    while d * d <= n and n % d != 0:
        d += 2
    return d * d > n


nums = input().split(" ")
nums = [int(x) for x in nums]
length = nums[0]
needed = nums[1]
count = 0

if needed == 1:
    print(1)
else:
    if needed > length:
        if isPrime(needed):
            print(0)
        else:
            for i in range(2, min(nums) + 1):
                if needed % i == 0:
                    # print("I == " ,i, " ")
                    if needed / i <= length:
                        count += 1
            print(count)
    else:
        if isPrime(needed):
            print(2)
        else:
            for i in range(1, min(nums) + 1):
                if needed % i == 0:
                    count += 1
            print(count)