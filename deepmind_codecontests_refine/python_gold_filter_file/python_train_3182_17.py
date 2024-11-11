import sys

n = int(sys.stdin.readline())
tmpl = list(map(int, sys.stdin.readline().split()))
strs = sys.stdin.read().splitlines()

for s in range(0, n):
    for ch in strs[s]:
        if ch in 'aeiouy':
            tmpl[s] -= 1
    if tmpl[s] != 0:
        print('NO')
        exit()

print('YES')
