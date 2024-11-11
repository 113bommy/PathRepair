t = int(input())

ns = []

for i in range(t):

    n = int(input())
    arr = list(map(int, input().split()))

    nums = set(arr)
    dct1 = {}
    dct2 = {num: 0 for num in nums}

    for idx, el in enumerate(arr):
        if el in dct1:
            dct2[el] = max(dct2[el], idx - dct1[el])
        else:
            dct2[el] = idx + 1
        dct1[el] = idx

    for el in dct2:
        dct2[el] = max(dct2[el], n - dct1[el])

    ans = []
    temp = sorted(nums, key=lambda x: dct2[x])
    index = 0

    mini = 10**20
    for k in range(1, n + 1):
        while index < len(temp) and dct2[temp[index]] == k:
            mini = min(mini, temp[index])
            index += 1       
        if mini == 10**20:
            ans.append(-1)
        else:
            ans.append(mini)

    ns.append(ans)


for el in ns:
    print(" ".join(list(map(str, el))))
