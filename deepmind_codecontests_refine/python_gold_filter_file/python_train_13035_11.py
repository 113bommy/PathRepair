import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n,s,k = [int(i) for i in sys.stdin.readline().split()]
    floors = set([int(i) for i in sys.stdin.readline().split()])
    for ans in range(1002):
        if s+ans<=n and s+ans not in floors:
            print(ans)
            break
        if s-ans>=1 and s-ans not in floors:
            print(ans)
            break
