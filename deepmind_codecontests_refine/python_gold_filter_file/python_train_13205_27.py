def comb(left, right):
    top = 1
    for i in range(left, left - right, -1):
        top *= i

    bottom = 1
    for i in range(1, right + 1):
        bottom *= i

    return top // bottom

n, a, b = map(int, input().split())
v = list(map(int, input().split()))

v.sort()

min_set = v[-a:]
print(sum(min_set) / len(min_set))
if len(set(min_set)) == 1:
    cnt = v.count(min_set[0])

    result = 0
    for i in range(a, min(cnt, b) + 1):
        result += comb(cnt, i)
    print(result)
else:
    print(comb(v.count(min_set[0]), min_set.count(min_set[0])))
