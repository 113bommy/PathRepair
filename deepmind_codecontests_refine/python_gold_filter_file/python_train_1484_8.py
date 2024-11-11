from sys import stdin, stdout
from math import sqrt

n = int(stdin.readline())

nums = sorted([int(x) for x in stdin.readline().split()])

if len(nums) == 1:
    print(nums[0])

else:
    primes = [2,3,5,7,11,13]

    for num in range(17,nums[-1]+1,2):
        sq = sqrt(num)
        valid = True
        for n in primes:
            if num%n == 0:
                valid = False
                break
            if n > sq:
                break
        if valid:
            primes.append(num)

    primes = {n:[200000,200000] for n in primes}

    for num in nums:
        rSet = []
        for p in primes:
            count = 0
            while num%p == 0:
                count += 1
                num = num//p

            if count < primes[p][0]:
                primes[p] = [count, primes[p][0]]
            elif count < primes[p][1]:
                primes[p][1] = count
            if primes[p][1] == 0:
                rSet.append(p)
        for p in rSet:
            del primes[p]

    base = 1

    for a in primes:
        base *= a ** primes[a][1]

    print(base)
