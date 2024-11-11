n, m = map(int, input().split())


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


arr1 = [int(z) for z in input().split()]
arr2 = [int(z) for z in input().split()]

arr1.sort()

res = []

for i in arr2:
    res.append(str(binsearch(arr1, i+.1)))

print(' '.join(res))
