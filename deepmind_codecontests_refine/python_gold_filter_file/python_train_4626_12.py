def main():
    from collections import defaultdict
    n = int(input())
    s = defaultdict(int)
    (aa, ab) = map(int, input().split(' '))
    l = []
    for i in range(n - 1):
        (a, b) = map(int, input().split(' '))
        l.append((a, b))
        while a < b:
            s[a] += 1
            a += 1
    r = 0
    while aa < ab:
        if s[aa] == 0:
            r += 1
        aa += 1
    return r
print(main())
