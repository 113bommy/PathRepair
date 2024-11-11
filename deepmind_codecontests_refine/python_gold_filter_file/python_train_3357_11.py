
def bsearch(l, r, x, n):
    while l <= r:

        mid = (l+r) // 2
        if mid - (mid // n) == x and mid % n != 0:
            return mid
        elif mid - (mid // n) < x:
            l = mid + 1
        else:
            r = mid - 1


t = int(input())
for i in range(t):
    n, k = [int(x) for x in input().split()]

    print(bsearch(1, 2*k, k, n))