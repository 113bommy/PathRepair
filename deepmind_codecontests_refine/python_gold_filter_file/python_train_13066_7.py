import sys

n = int(sys.stdin.readline())

ans = []
s = set()
left = 1

for i, e in enumerate(map(int, sys.stdin.readline().split()), 1):
    if e in s:
        s = set()
        ans += [(left, i)]
        left = i + 1
    else:
        s.add(e)
if ans:
    sys.stdout.write(f"{len(ans)}\n")
    ans[-1] = ans[-1][0], n
    for a, b in ans:
        sys.stdout.write(f"{a} {b}\n")
else:
    sys.stdout.write("-1\n")
