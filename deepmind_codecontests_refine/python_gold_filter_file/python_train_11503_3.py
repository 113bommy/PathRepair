import sys


n, m = map(int, str.split(sys.stdin.readline()))
pd = ph = None
top = None
for _ in range(m):

    d, h = map(int, str.split(sys.stdin.readline()))
    if pd is None:

        top = d - 1 + h

    else:

        if pd and d - pd < abs(h - ph):

            print("IMPOSSIBLE")
            exit()

        delta = d - pd - 1 - abs(h - ph)
        top = max(top, max(ph, h) + (delta // 2) + (delta % 2))

    pd, ph = d, h

top = max(top, h + n - d)
print(top)
