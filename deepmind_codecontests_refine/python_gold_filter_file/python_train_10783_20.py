
def work(days, n, m):
    # m < n
    #print(days, n, m)
    k = days - (m+1)
    loss = (1 + k) * k // 2
    #print(loss)
    return n - loss - days <= 0


def main():
    n, m = [int(x) for x in input().split()]
    if m >= n:
        print(n)
        return
    left = m + 1
    right = n
    while left < right:
        mid = (left + right) // 2
        if work(mid, n, m):
            right = mid
        else:
            left = mid + 1
    print(left)

if __name__ == "__main__":
    main()
