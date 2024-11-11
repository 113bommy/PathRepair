import sys
data1 = sys.stdin.read()
data = data1.split('\n')
data.remove('')
n = int(data[0])
k = list(map(int, data[1].split(' ')))
p1 = n
p2 = 2
solve = [n]
while p1 > 1 and p2 > 1:
    p2 = k[p1-2]
    solve.append(p2)
    p2 = p2 - 2
    p1 = k[p2]
    if p1 >= 1 and p2 >= 1:
        solve.append(p1)
if solve.count(1) == 0:
    solve.append(1)
solve.reverse()
print(*solve)


