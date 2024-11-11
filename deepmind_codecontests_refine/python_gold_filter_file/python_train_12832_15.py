import math


def makeTeam(arr, n, w):
    l = 0
    r = n-1
    count = 0
    while l < r:
        teamWeight = arr[l]+arr[r]
        if teamWeight == w:
            count += 1
            l += 1
            r -= 1
        elif teamWeight < w:
            l += 1
        else:
            r -= 1
    return count


def Solution(arr, n):
    if n == 1:
        print(0)
        return
    res = 0
    arr = sorted(arr)
    maxW = arr[n-2]+arr[-1]
    for i in range(arr[0], maxW+1):
        res = max(res, makeTeam(arr, n, i))
    print(res)

    # op = []
for t in range(int(input())):
    N = int(input())
    arr = list(map(int, input().split()))
    Solution(arr,  N)
# print(op)
#
