#   Author: yumtam
#   Created at: 2021-04-11 23:19

def solve():
    n, c = input_as_list()
    a = input_as_list()
    b = input_as_list()

    ans = float('inf')
    coins, time = 0, 0

    for i in range(n):
        ans = min(ans, time + ceil_div(c - coins, a[i]))
        if i < n-1:
            days = ceil_div(b[i] - coins, a[i])
            time += days + 1
            coins += days * a[i] - b[i]

    print(ans)


def ceil_div(a, b):
    return max(0, (a + b - 1) // b)

def input_as_list():
    return [int(t) for t in input().split()]

for _ in range(int(input())):
    solve()
