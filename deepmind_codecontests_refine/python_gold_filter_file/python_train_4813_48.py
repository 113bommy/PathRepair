maxn = 15000
maxx = 10000000000

bf = [[] for x in range(maxn)]
nx = [[] for x in range(maxn)]


for i in range(1, maxn):
    for j in range(i, maxn, i):
        bf[j].append(i)
        nx[i].append(j)

tc = int(input())

for asd in range(tc):
    a, b, c = [int(x) for x in input().split()]

    mi = maxx
    nums = (0, 0, 0)

    for i in range(1, maxn):
        le = maxx
        for j in bf[i]:
            if abs(a - j) < abs(a - le):
                le = j

        ri = maxx
        for j in nx[i]:
            if abs(c - j) < abs(c - ri):
                ri = j

        if abs(c - ri) + abs(a - le) + abs(i - b) < mi:
            nums = (le, i, ri)
            mi = abs(c - ri) + abs(a - le) + abs(i - b)

    print(mi)
    print(nums[0], nums[1], nums[2])
