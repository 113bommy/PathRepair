q = int(input())

for i in range(q):
    stupid_space = input()
    n, k = map(int, input().split())
    spaces = [2**31] * n

    for ac, temp in zip(map(int, input().split()), map(int, input().split())):
        spaces[ac - 1] = temp

    for k in range(1, n):
        spaces[k] = min(spaces[k], spaces[k - 1] + 1)

    for l in range(n - 2, -1, -1):
        spaces[l] = min(spaces[l], spaces[l + 1] + 1)

    print(' '.join(str(s) for s in spaces))
