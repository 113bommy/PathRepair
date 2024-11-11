def abc():
    a, b, c = map(int, input().split())
    n = range(a, b + 1)
    for s in sorted(set(n[:c]) | set(n[-c:])):
        print(s)


abc()
