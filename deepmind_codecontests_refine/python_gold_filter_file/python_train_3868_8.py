def recurse(n):
    if(n < 10):
        return max(1, n)
    return max(recurse(n // 10) * (n % 10), recurse(n // 10 - 1) * 9)


n = int(input())
print(recurse(n))
