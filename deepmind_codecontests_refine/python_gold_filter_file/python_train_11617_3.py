n = int(input())
days = list(map(int,input().split()))
seen = set()
m = n
res = []
for k in range(n):
    res.append([])
for k in range(n):
    if days[k] == m:
        res[k].append(str(m))
        i = 1
        last = m
        while m-i in seen:
            res[k].append(str(m-i))
            last = last-1
            i += 1
        m = last-1
    else:
        seen.add(days[k])
for day in res:
    print(" ".join(day))
