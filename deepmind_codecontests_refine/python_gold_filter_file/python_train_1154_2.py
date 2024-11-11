def death(n, m, lst):
    s, result = 0, list()
    for i in range(n):
        s += lst[i]
        result.append(s // m)
        s %= m
    return result


N, M = [int(j) for j in input().split()]
a = [int(j) for j in input().split()]
print(*death(N, M, a))
