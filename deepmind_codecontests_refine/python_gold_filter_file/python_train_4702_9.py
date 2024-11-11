from collections import deque
from sys import stdin

LIMIT = 2 ** 32 - 1

def solve():
    loops = deque([1])
    total = 0
    n = int(stdin.readline().rstrip())
    for _ in range(n):
        line = stdin.readline().rstrip()
        if line[0] == 'a':
            total += loops[-1]
        elif line[0] == 'f':
            loops.append(min(loops[-1] * int(line[3:]), LIMIT + 1))
        else:
            loops.pop()
        if total > LIMIT:
            print('OVERFLOW!!!')
            return
    print(total)

if __name__ == '__main__':
    solve()