import sys

n = int(input())

A = []

for _ in range(2 * n - 2):
    A += [input()]
    if len(A[-1]) == n - 1:
        longest = A[-1]

letters = "abcdefghijklmnopqrstuvwxyz"

C = ""

for i in range(2):
    for x in letters:
        pre, suf = 0, 0

        if i == 0:
            B = longest + x
        else:
            B = x + longest

        all_have = True

        for w in A:
            a, b = False, False
            if B[:len(w)] == w:
                a = True
                pre += 1
            if B[-len(w):] == w:
                b = True
                suf += 1
            if not (a or b):
                all_have = False

        if pre >= n - 1 and suf >= n - 1 and all_have:
            C = B

if C == "":
    print(-1)
    sys.exit(0)

pre, suf = 0, 0
PRE, SUF = set(), set()
BOTH = {}

result = ["X"] * (2 * n - 2)

for i, w in enumerate(A):
    a = w == C[:len(w)] and w not in PRE
    b = w == C[-len(w):] and w not in SUF
    if w in BOTH:
        PRE.add(w)
        SUF.add(w)
        result[i] = "P"
        result[BOTH[w]] = "S"
    elif a and b:
        BOTH[w] = i
        pre += 1
        suf += 1
    elif a:
        pre += 1
        PRE.add(w)
        result[i] = "P"
    else:
        suf += 1
        SUF.add(w)
        result[i] = "S"

for i in range(len(result)):
    if result[i] == "X":
        if suf < n - 1:
            suf += 1
            SUF.add(w)
            result[i] = "S"
        else:
            pre
            PRE.add(w)
            result[i] = "P"

print(''.join(result))
