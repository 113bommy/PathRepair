import itertools
import sys
H, W = [int(i) for i in input().split(' ')]

cross = [[0] * (H + W -1) for _ in range(H + W - 1)]
for i, line in enumerate(sys.stdin):
    for j, c in enumerate(line.strip()):
        if c == "#":
            cross[i+j][i-j+W-1] = 1

across = [[0] + list(itertools.accumulate(xs)) for xs in cross]
r_cross = [[xs[i] for xs in cross] for i in range(H + W - 1)]
across2 = [[0] + list(itertools.accumulate(xs)) for xs in r_cross]

r = 0
for i in range(H+W-1):
    for j in range(H+W-1):
        if cross[i][j] != 1:
            continue
        for k in range(j+1, H+W-1):
            if cross[i][k] == 1:
                if i - (k-j) >= 0:
                    r += across[i - (k - j)][k+1] - across[i - (k - j)][j]
                if i + (k-j) < H + W - 1:
                    r += across[i + (k - j)][k+1] - across[i + (k - j)][j]

for i in range(H+W-1):
    for j in range(H+W-1):
        if cross[j][i] != 1:
            continue
        for k in range(j+1, H+W-1):
            if cross[k][i] == 1:
                if i - (k-j) >= 0:
                    r += across2[i - (k - j)][k] - across2[i - (k - j)][j+1]
                if i + (k-j) < H + W - 1:
                    r += across2[i + (k - j)][k] - across2[i + (k - j)][j+1]

print(r)
