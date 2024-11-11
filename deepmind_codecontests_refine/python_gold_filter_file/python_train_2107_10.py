import math

t = int(input())

for tc in range(t):

    n = int(input())
    arr = [int(z) for z in input().split()]

    if len(set(arr)) == 1:
        print(1)
        print(*([1]*n))
        continue

    if n % 2 == 0:
        print(2)
        print(*([1, 2]*(n//2)))
        continue

    model = ([1, 2] * math.ceil(n/2))[:n]

    p = -1

    for i in range(1, n):
        if arr[i] == arr[i-1]:
            p = i
            break

    if p > 0:
        r = model[:p]
        r.append(r[-1])
        r += model[p:]
        r = r[:n]
    elif arr[0] != arr[-1]:
        r = model[:n-1]
        r.append(3)
    else:
        r = model

    print(len(set(r)))
    print(*r)

