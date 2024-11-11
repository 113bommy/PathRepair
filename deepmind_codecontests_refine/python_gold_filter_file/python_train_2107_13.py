t = int(input())
for T in range(t):
    n = int(input())
    types = list(map(int, input().split()))
    cols = n * [1]
    used = 1
    idx_eq = -1
    for i in range(1, n):
        if types[i] == types[i-1]:
            cols[i] = cols[i - 1]
            idx_eq = i
        else:
            used = 2
            cols[i] = 3 - cols[i - 1]
    if types[n - 1] != types[0] and cols[n - 1] == cols[0]:
        if idx_eq == -1:
            used = 3
            cols[n - 1] = 3
        else:
            for j in range(idx_eq, n):
                cols[j] = 3 - cols[j]
    print(used)
    print(' '.join(map(str, cols)))
