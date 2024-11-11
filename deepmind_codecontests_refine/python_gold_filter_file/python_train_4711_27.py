def read_int():
    return int(input())


def read_string_array():
    for s in input().split():
        yield s


def read_int_array():
    for s in read_string_array():
        yield int(s)


def read_line():
    return input()


def solve(s):
    s = sorted(s)
    min_diff = abs(s[0] - s[1])
    for i in range(len(s)-1):
        a = abs(s[i]-s[i+1])
        if a < min_diff:
            min_diff = a
    return min_diff


if __name__ == '__main__':
    T = read_int()
    for _ in range(T):
        #  read inputs
        N = read_int()
        S = read_int_array()
        # solve
        print(solve(S))
