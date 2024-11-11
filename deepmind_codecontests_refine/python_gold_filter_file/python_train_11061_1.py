from sys import stdin

def readline():
    return stdin.readline()

#tests = int(readline())

def solve(n, a, b):
    shifts = []
    pos = [0] * n
    for i in range(0, n):
        pos[b[i]] = i

    for i in range(0, n):
        shift = i - pos[a[i]]
        if shift < 0:
            shift += n
        shifts.append(shift)

    shifts.sort()
    result = 1
    shifts = [-1, *shifts]
    for i in range(1, n + 1):
        if shifts[i] != shifts[i - 1]:
            pos = i + 1
            while pos < n + 1 and shifts[i] == shifts[pos]:
                pos += 1
            result = max(result, pos - i)

    return result

#for t in range(0, tests):
n = int(readline().rstrip("\n"))
#n, m = list(map(int, readline().rstrip("\n").split(' ')))
a = list(map(lambda x: int(x) - 1, readline().split(' ')))
b = list(map(lambda x: int(x) - 1, readline().split(' ')))

print(solve(n, a, b))