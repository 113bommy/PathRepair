import sys
def read_line():
    return sys.stdin.readline()
def solve(n, a, b):
    start, end = 97, 97 + b - 1
    lst = [chr(i) for i in range(start, end)]
    for i in range(a - len(lst)):
        lst.append(chr(end))
    l = 0
    i = len(lst) - 1
    while i <= n:
        if i - l > a:
            lst.append(lst[l])
            l += 1
        i += 1
    print(''.join(lst))
n = int(read_line())
for i in range(n):
    line = read_line().split(' ')
    solve(int(line[0]), int(line[1]), int(line[2]))