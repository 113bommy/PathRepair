from sys import stdin

n, m = [int(x) for x in stdin.readline().rstrip().split()]
h = stdin.readline().rstrip()
v = stdin.readline().rstrip()
con = h[0] + v[0] + h[n - 1] + v[m - 1]

if con == '<v>^' or con == '>^<v':
    print('YES')
else:
    print('NO')
