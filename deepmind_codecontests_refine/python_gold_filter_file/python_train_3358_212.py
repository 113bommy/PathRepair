def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    ans = [i + 1 - i % 2 for i in range(n)]
    print(' '.join(map(str, ans)))
