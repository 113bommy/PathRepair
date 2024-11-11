n = int(input())
v = list(map(int, input().split()))
v = sorted([(v[i], i * 2 + 1) for i in range(n)], reverse=True)
print('\n'.join([str(v[i][1]) + ' ' + str(v[i + 1][1]) for i in range(n - 1)]))
r = [i[1] for i in v]
for i in range(n):
    print(v[i][1] + 1, r[v[i][0] + i - 1])
    if v[i][0] + i == len(r):
        r.append(v[i][1] + 1)