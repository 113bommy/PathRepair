# Aizu Problem 0186: Aizu Chicken
#
import sys, math, os, bisect

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


def aizu_chicken(q1, b, c1, c2, q2):
    for i in range(q2, 0, -1):
        cj = i * c1
        normal = int((b - cj) // c2)
        if i + normal < q1:
            continue
        elif normal >= 0:
            print(i, normal)
            break
    else:
        print("NA")


while True:
    inp = [int(_) for _ in input().split()]
    if len(inp) == 1:
        break
    q1, b, c1, c2, q2 = inp[:]
    aizu_chicken(q1, b, c1, c2, q2)