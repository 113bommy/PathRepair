def read_tokens():
    return input().strip().split(' ')


def read_ints():
    return [int(s) for s in read_tokens()]


n, = read_ints()
arr = read_ints()


def solve(arr: list):
    n = len(arr)
    b = []
    for i in range(n):
        b.append((arr[i], i))
    b.sort(reverse=True)
    res = 0
    x = 0
    for i in range(n):
        res += b[i][0]*x + 1
        x = x + 1

    print(res)
    for i in range(n):
        print(b[i][1] + 1, end=" ")
    print()


solve(arr)
