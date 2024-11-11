def main():
    n, k = map(int, input().split())
    n -= 1
    k -= 1
    if n == 0:
        minSplitters = 0
    elif n <= k:
        minSplitters = 1
    elif n > sum_consecutive(k):
        minSplitters = -1
    else:
        minSplitters = min_splitters(n, k)

    print(minSplitters)


def min_splitters(n, k):
    low, high = 1, k
    while low < high:
        mid = (low + high) // 2
        summation = sum_consecutive2(mid, k)
        if summation == n:
            return k - mid + 1
        elif summation > n:
            low = mid + 1
        else:
            high = mid

    return k - low + 2


def sum_consecutive(num):
    return int(0.5 * num * (num + 1))


def sum_consecutive2(num1, num2):
    return sum_consecutive(num2) - sum_consecutive(num1 - 1)


if __name__ == '__main__':
    main()
