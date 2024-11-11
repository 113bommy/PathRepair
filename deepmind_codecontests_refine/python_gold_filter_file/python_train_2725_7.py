for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input()))
    numsarr = [[] for _ in range(10)]

    for i, num in enumerate(nums):
        numsarr[num].append(i)
    arr1 = []
    arr2 = []
    fl = False
    for i, arr in enumerate(numsarr):
        if fl:
            break
        for j in arr:
            if (not arr1 or arr1[-1] <= j) and (not arr2 or nums[arr2[0]] >= nums[j]):
                arr1.append(j)
            elif not arr2 or arr2[-1] <= j:
                arr2.append(j)
            else:
                print('-')
                fl = True
                break
        if fl:
            break
    if fl:
        continue
    ans = [2] * n
    for i in arr1:
        ans[i] = 1
    for i in arr2:
        ans[i] = 2
    print(*ans, sep='')
