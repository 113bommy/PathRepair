from random import randint

n, l = list(map(int, input().split()))
s = list(map(int, input().split()))
s.sort()


def f(x):
    d = x / 2
    if s[0] - 0 > d:
        return False
    if l - s[-1] > d:
        return False
    for x in range(len(s) - 1):
        if s[x + 1] - s[x] > 2 * d:
            return False
    return True

left = 0
right = l * 2
while left != right - 1:
    mid = (left + right) // 2
    if f(mid):
        right = mid
    else:
        left = mid
print(right / 2)
