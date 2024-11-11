n, m = (int(x) for x in input().split())
a = []
for i in range(n):
    a.append(list(input()))
for iy in range(n):
    for ix in range(m):
        if a[iy][ix] == '*':
            continue
        else:
            c = 0
            for i in range(-1,2):
                for j in range(-1,2):
                    if i == j == 0:
                        continue
                    if ix+j < 0 or iy+i < 0 or ix+j >= m or iy+i >= n:
                        continue
                    if a[iy+i][ix+j] == '*':
                        c += 1
                    else:
                        continue
            if a[iy][ix] == '.':
                if c == 0:
                    continue
                else:
                    print("NO")
                    exit(0)
            else:
                if c == int(a[iy][ix]):
                    continue
                else:
                    print("NO")
                    exit(0)
print("YES")