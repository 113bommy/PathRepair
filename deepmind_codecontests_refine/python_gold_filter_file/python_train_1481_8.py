import bisect

BIG = 2**31

n = int(input())
a = sorted(map(lambda s: -int(s), input().split()))
n=len(a)

def mv(a, l, r, cor, bs):
    if l+1 == r:
        return 0
    elif l==r:
        return BIG
    elif a[l]==a[r-1]:
        return 0
    corp = cor + 2 ** bs
    sep = bisect.bisect_right(a, -corp, l, r)
    lm = mv(a, l, sep, corp, bs - 1)
    rm = mv(a, sep, r, cor, bs - 1)
    if sep==l:
        return rm
    elif sep==r:
        return lm
    else:
        return min(lm,rm) + 2**bs


bs = (-a[0]).bit_length()
cor = 0
print(mv(a, 0, n, cor, bs - 1))
