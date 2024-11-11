a = input()
n = len(a)
if a[:n // 2] == (a[(n + 1) // 2:])[::-1]:
    if a.count(a[0]) == n:
        print(0)
    else:
        print(n - 1)
else:
    print(n)
