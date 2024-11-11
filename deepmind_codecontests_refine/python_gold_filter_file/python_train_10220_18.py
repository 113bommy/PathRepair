def prices(n, k, lst):
    if len(lst) == 1:
        return lst[0] + k
    result = 0
    lst[0] += k
    for i in range(1, n):
        c = abs(lst[i] - lst[0])
        if c <= k:
            result = lst[0]
        else:
            result = -1
            break
    return result


m = int(input())
a = list()
for j in range(m):
    N, K = [int(x) for x in input().split()]
    b = [int(y) for y in input().split()]
    a.append(prices(N, K, sorted(list(b))))
for elem in a:
    print(elem)
