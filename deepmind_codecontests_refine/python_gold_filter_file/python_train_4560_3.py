N, K = list(map(int, input().split()))
A = list(map(int, input().split()))
F = list(map(int, input().split()))

A.sort()
F.sort(reverse=True)

l = -1
r = A[-1] * F[0]


def ok(c):
    s = 0
    for a, f in zip(A, F):
        s += max(0, a - c//f)
    return s <= K


while r - l > 1:
    c = (l+r)//2
    if ok(c):
        r = c
    else:
        l = c

print(r)
