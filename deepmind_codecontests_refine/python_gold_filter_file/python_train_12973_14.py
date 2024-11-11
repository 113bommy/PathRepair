def solve(n):
    a = n ** 0.5
    b = int(a)
    if a== int(a):
        return 4 * int(a)
    else:
        if n > b * b and n <= b*(b + 1):
            return 4 * b +2
        else:
            return 4 * (b+1)


n = int(input())
print(solve(n))
