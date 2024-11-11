from math import floor, sqrt


def solve(n):
    ans = set()
    for i in range(1, floor(sqrt(n))+1):
        ans.add(i)
        ans.add(floor(n / i))
    ans.add(0)

    return len(ans), list(map(str, sorted(ans)))


if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n = int(input())

        nums, ratings = solve(n)

        print(nums)
        print(' '.join(ratings))