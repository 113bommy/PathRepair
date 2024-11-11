import sys


def read(s):
    return list(s[:len(s) - 1])


groups = sys.stdin.readline()
for i in range(int(groups)):
    a = 0
    n = sys.stdin.readline()
    n = n.split(" ")
    lines = int(n[0])
    for j in range(lines - 1):
        l = read(sys.stdin.readline())
        if l[-1] == "R":
            a += 1
    l = read(sys.stdin.readline())
    for i in l:
        if i == "D":
            a += 1
    print(a)


