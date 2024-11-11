import sys

a = 'abcdefghijklmnopqrstuvwxyz'
for i in sys.stdin.readlines():
    s = i.strip()
    for j in range(1, 27):
        t = s.translate(str.maketrans(a, a[j:] + a[:j]))
        if 'the' in t or 'this' in t or 'that' in t:
            print(t)