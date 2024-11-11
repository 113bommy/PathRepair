def main():
    n = int(input())
    mi = int(1e10)
    ma = int(-1e10)
    l = []
    for i in range(n):
        (a, b) = map(int, input().split(' '))
        mi = min(mi, a)
        ma = max(ma, b)
        l.append((a, b))
    for i, (a, b) in enumerate(l):
        if a == mi and b == ma:
            return i + 1
    return -1

print(main())

