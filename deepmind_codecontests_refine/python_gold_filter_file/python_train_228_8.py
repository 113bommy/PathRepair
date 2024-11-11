alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

t = int(input())

def binsearch(nums, target):
    left = 0
    right = len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] > target:
            right = mid - 1
        elif nums[mid] < target:
            left = mid + 1

    return left


for tc in range(t):

    n, m = map(int, input().split())

    s = input()
    fails = [int(z)-1 for z in input().split()]

    occ = {}

    fails.sort()

    for i in alphabet:
        occ[i] = 0

    for i in range(n):
        pl = binsearch(fails, i-.1)
        occ[s[i]] += m - pl
        #print(pl, fails)

    for i in range(n):
        occ[s[i]] += 1

    res = []

    for i in range(26):
        res.append(occ[alphabet[i]])

    print(*res)



