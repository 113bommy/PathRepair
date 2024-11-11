from collections import Counter


def pair(n):
    res = 0
    for i in range(n):
        res += i
    return res


n = int(input().strip())

name_counter = Counter()
for _ in range(n):
    name_counter[input().strip()[0]] += 1

res = 0
for count in name_counter.values():
    # print(count, count // 2, count // 2 + count % 2)
    res += pair(count // 2) + pair(count // 2 + count % 2)
print(res)