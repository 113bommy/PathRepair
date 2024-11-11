def bin_poisk(q, arr):
    l = 0
    r = len(arr)
    while r - l > 1:
        x = (l + r) // 2
        if arr[x] <= q:
            l = x
        else:
            r = x
    if arr[-1] <= q:
        return -1
    if arr[l] <= q:
        if r == len(arr):
            return arr[-1]
        return arr[r]
    return arr[l]


n = int(input())

for i in range(n):
    d = dict()
    nabor = input()
    t = input()
    e = len(t)
    answer = 0
    for j in range(len(nabor)):
        if nabor[j] not in d:
            d[nabor[j]] = []
        d[nabor[j]].append(j)
    o = -1
    while o < e - 1:
        answer += 1
        w = -1
        while o < e - 1:
            if t[o + 1] not in d:
                answer = -1
                break
            q = bin_poisk(w, d[t[o + 1]])
            if q == -1:
                break
            w = q
            o += 1
        if answer == -1:
            break
    print(answer)