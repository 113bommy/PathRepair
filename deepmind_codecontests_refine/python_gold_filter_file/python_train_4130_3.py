def duplicates(n, a):
    b = list()
    for elem in a:
        b.append(n - a[::-1].index(elem) - 1)
    c = sorted(list(set(b)))
    d = list()
    for elem in c:
        d.append(a[elem])
    print(len(d))
    return d


m = int(input())
lst = [int(j) for j in input().split()]
print(*duplicates(m, lst))
