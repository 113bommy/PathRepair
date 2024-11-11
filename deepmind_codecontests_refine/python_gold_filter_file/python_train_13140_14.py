from sys import stdin

def inp():
    return stdin.readline().strip()

t = int(inp())
for _ in range(t):
    n = int(inp())
    a = [int(x) for x in inp().split()]
    a.sort(reverse = True)
    print(*a)