from sys import stdin, stdout

# 0 1 2 3 4 5 6 7 8 9
# 9 8 7 6 5 4 3 2 1 (0) 9
# 1 2 3 4 5 6 7 8 (9)   8
# 8 7 6 5 4 3 2 (1)     7
# 2 3 4 5 6 7 (8)       6
# 7 6 5 4 3 (2)         5
# ..........
t = int(stdin.readline())
for _ in range(t):
    n = int(stdin.readline())
    a = stdin.readline().strip()
    b = stdin.readline().strip()

    ans = []
    idx = 0
    flip = False
    for i in range(n-1, -1, -1):
        if (not flip and a[idx] == b[i]) or (flip and a[idx] != b[i]):
            ans.append(1)
        ans.append(i+1)

        if flip:
            idx -= i
        else:
            idx += i

        flip = not flip

    stdout.write(str(len(ans)) + ' ')
    if len(ans) > 0:
        stdout.write(' '.join(map(str, ans)) + '\n')
