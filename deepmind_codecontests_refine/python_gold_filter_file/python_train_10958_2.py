t = int(input())
for _ in range(t):
    arr1 = [int(p) for p in input().split()]
    arr2 = [int(p) for p in input().split()]
    s = 0
    n2 = arr1[2] # no of 2 in arr1
    j = min(n2, arr2[1]) # min in both
    s += 2 * j
    arr2[1] -= j
    arr1[2] -= j
    n2 -= j


    j = min(n2, arr2[2])  # min in both
    arr2[2] -= j
    arr1[2] -= j
    n2 -= j


    # for 0
    n0 = arr1[0]
    k = min(n0, arr2[2])
    n0 -= k
    arr2[2] -= k
    arr1[0] -= k

    k = min(n0, arr2[1])
    n0 -= k
    arr2[1] -= k
    arr1[0] -= k

    k = min(n0, arr2[0])
    n0 -= k
    arr2[0] -= k
    arr1[0] -= k

    # for 1
    s -= 2*min(arr1[1], arr2[2])
    print(s)