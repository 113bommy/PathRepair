n = int(input())
d = {}
for i in range(n):
    s = str(input())
    d[s] = [0, 0, 0]
for i in range(n * (n - 1) // 2):
    teams, results = map(str, input().split(' '))
    a, b = map(str, teams.split('-'))
    c, e = map(int, results.split(':'))
    d[a][1] += c
    d[a][2] += e
    d[b][1] += e
    d[b][2] += c
    if c == e:
        d[a][0] += 1
        d[b][0] += 1
    elif c > e:
        d[a][0] += 3
    else:
        d[b][0] += 3
for key in d.keys():
    d[key][1], d[key][2] = d[key][1] - d[key][2], d[key][1]
p = set()
for i in sorted(d.items(), key=lambda x: x[1], reverse=True)[:n // 2]:
    p.add(i[0])
for i in sorted(p):
    print(i)
