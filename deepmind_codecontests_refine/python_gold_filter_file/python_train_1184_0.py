def sum(n):
    return (n * (n + 1)) // 2


def range_sum(left, right):
    return sum(right) - sum(left - 1)


def binary_search(k, n):
    low, high, mid = 1, k, 0

    while low <= high:
        mid = (low + high) // 2
        s = range_sum(mid, k)

        if s == n:
            return k - mid + 1
        elif s > n:
            low = mid + 1
        else:
            high = mid - 1

    return k - low + 2


n, k = map(int, input().split(' '))
if n == 1:
    print(0)
elif n <= k:
    print(1)
else:
    n -= 1
    k -= 1

    if n > sum(k):
        print(-1)
    else:
        print(binary_search(k, n))
