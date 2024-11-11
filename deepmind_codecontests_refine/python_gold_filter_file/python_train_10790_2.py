# https://codeforces.com/contest/950/problem/A

l, r, a = map(int, input().split())

if l < r:
    diff = r - l
    if diff > a:
        print((l + a) * 2)
    else:
        print(l + diff + r + ((a - diff) // 2) * 2)
elif l == r:
    print(l + r + (a // 2) * 2)
elif r < l:

    diff = l - r
    if diff > a:
        print((r + a) * 2)
    else:
        print(r + diff + l + ((a - diff) // 2) * 2)
