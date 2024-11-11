import sys

t = int(sys.stdin.readline().strip())
for i in range(0, t):
    n = int(sys.stdin.readline().strip())
    c = 4 * 10 ** 2
    d = n // (c * (c-1) // 2)
    b = n % (c * (c-1) // 2)

    print("133" + "7"*b + "3" * (c-2) + "7"*d)
