def pair_programming(n,a,b):
    res = []
    i,j = 0,0
    num = n
    while i < len(a) and j < len(b):
        if a[i] == 0 and b[j] == 0:
            res.extend([0,0])
            i += 1
            j += 1
            num += 2
        elif a[i] == 0:
            res.append(0)
            num += 1
            i += 1
        elif b[j] == 0:
            res.append(0)
            num += 1
            j += 1
        else:
            if a[i] < b[j]:
                if a[i] <= num:
                    res.append(a[i])
                    i += 1
                else:
                    return None

            else:
                if b[j] <= num:
                    res.append(b[j])
                    j += 1
                else:
                    return None

    idx, arr = None, None
    
    if i == len(a):
        idx = j
        arr = b
    else:
        idx = i
        arr = a
    
    for i in range(idx,len(arr)):
        if arr[i] == 0:
            res.append(0)
            num += 1
        else:
            if arr[i] <= num:
                res.append(arr[i])
            else:
                return None

    return res


N = int(input())

for _ in range(N):
    input()
    k = [int(s) for s in input().split()]
    a = [int(s) for s in input().split()]
    b = [int(s) for s in input().split()]
    res = pair_programming(k[0],a,b)
    if res:
        print(*res)
    else:
        print(-1)
