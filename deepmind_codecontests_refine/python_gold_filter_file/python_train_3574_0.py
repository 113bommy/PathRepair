from sys import stdin, stdout


def bsearch(li, v):
    l, r = 0, len(li)
    while l < r:
        m = l + (r-l)//2
        if li[m] < v:
            l = m+1
        else:
            r = m
    lower = l

    l, r = 0, len(li)
    while l < r:
        m = l + (r-l)//2
        if li[m] <= v:
            l = m+1
        else:
            r = m
    upper = l
    return [lower, upper]


def solve():
    n, x = map(int, stdin.readline().split())
    li = list(map(int, stdin.readline().split()))
    li.sort()
    p = bsearch(li, x)
    cnt = 0
    if p[0] == p[1]:
        li.insert(p[0], x)
        p[1] += 1
        n += 1
        cnt += 1

    mid = li[(n-1)//2]
    if x < mid:
        cnt += max(0, (n-p[1]) - p[1])
    elif x > mid:
        cnt += max(0, p[0] - (n-p[0]-1))

    print(cnt)


if not __debug__:
    stdin = open("input.txt", "r")
tcs = int(stdin.readline()) if not __debug__ else 1
t = 1
while t <= tcs:
    solve()
    t += 1
