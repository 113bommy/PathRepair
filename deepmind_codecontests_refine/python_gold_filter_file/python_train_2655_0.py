n = int(input())
a = list(map(int, input().split()))

if n == 1:
    print(0)
else:

    total = 0
    turns = -1
    idx = 0
    d = 'r'
    while total <= n-1:

        if a[idx] != -1 and a[idx] <= total:
            total += 1
            a[idx] = -1

        if total == n:
            break

        if idx == len(a) - 1:
            d = 'l'
            turns += 1
        elif idx == 0:
            d = 'r'
            turns += 1

        if d == 'l':
            idx -= 1
        elif d == 'r':
            idx += 1

        #print(total, idx, turns, d, a[idx], a)

    print(turns)