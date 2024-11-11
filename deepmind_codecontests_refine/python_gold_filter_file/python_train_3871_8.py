def cond(a, n, k, v):
    s = 0
    for i in range(n // 2, n):
        s += max(0, v - a[i])
    return s <= k

def bin_search(a, n, k):
    left, right = -1, 10 ** 18
    while right - left > 1:
        mid = (right + left) // 2
        if cond(a, n, k, mid):
            left = mid
        else:
            right = mid
    if left < 0:
        return right
    return left

def main():
    n, k = map(int, input().split())
    numbers = list(map(int, input().split()))
    numbers.sort()
    print(bin_search(numbers, n, k))

main()
