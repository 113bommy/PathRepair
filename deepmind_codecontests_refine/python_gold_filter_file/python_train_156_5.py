import sys

def binary_search(left, right, count):
    while right - left > 1:
        middle = (left + right) // 2
        if middle * (middle + 1) // 2 < count:
            left = middle
        else:
            right = middle
    if right * (right + 1) // 2 < count:
        return right
    else:
        return left

if __name__ == "__main__":
    n, k = [int(i) for i in sys.stdin.readline().strip().split()]
    id = [int(i) for i in sys.stdin.readline().strip().split()]

    pos = binary_search(0, n, k)
    kth = k - pos * (pos + 1) // 2 - 1

    print(id[kth])
