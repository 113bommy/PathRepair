def solve():
    n = int(input())
    nums = list(map(int, input().split()))
    require = n / 2.0
    if len(list(filter(lambda x: x > 0, nums))) >= require:
        print(1)
    elif len(list(filter(lambda x: x < 0, nums))) >= require:
        print(-1)
    else:
        print(0)


if __name__ == '__main__':
    solve()
