import sys

IS_INTERACTIVE = False
input = input  # type: ignore

# input: function
if not IS_INTERACTIVE:
    *data, = sys.stdin.read().split("\n")[::-1]

    def input():  # type: ignore
        return data.pop()

def fprint(*args, **kwargs):
    print(*args, **kwargs, flush=True)

def eprint(*args, **kwargs):
    print(*args, **kwargs, file=sys.stderr)

output = []
for _ in range(int(input())):
    n, m = map(int, input().split())
    free = set(range(n))
    for _ in range(m):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        c -= 1
        if b in free:
            free.remove(b)
    free = next(iter(free))
    for i in range(n):
        if i != free:
            output.append("%s %s" % (free + 1, i + 1))
print("\n".join(output))

