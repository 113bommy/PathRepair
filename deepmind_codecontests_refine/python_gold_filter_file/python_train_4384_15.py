import math

def input_ints():
    return list(map(int, input().split()))

def solve():
    x, y, n = input_ints()
    ans = 0
    for i in range(n):
        ans += 2 * (x + y) - 4
        x -= 4
        y -= 4
    print(ans)

if __name__ == '__main__':
    solve()
