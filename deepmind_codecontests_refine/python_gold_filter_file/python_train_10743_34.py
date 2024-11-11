def solve(n, m, cs):
    if m < n or n < 3:
        # Not enough chains to work with
        return -1, None

    a, b = None, None
    a_ind, b_ind = None, None
    for i, c in enumerate(cs, 1):
        if a is None or c < a:
            b = a
            b_ind = a_ind
            a = c
            a_ind = i
        elif b is None or c < b:
            b = c
            b_ind = i

    # Use the first n chains
    connections = [[i, j]
                   for i, j in zip(range(1, n), range(2, n + 1))] + [[n, 1]]
    total = 2 * sum(cs)

    leftover_chains = m - n
    total += (a + b) * leftover_chains
    connections += [a_ind, b_ind] * leftover_chains

    return total, connections


for _ in range(int(input())):
    n, m = map(int, input().split())
    cs = [int(c) for c in input().split()]

    total, connections = solve(n, m, cs)
    print(total)
    if total != -1:
        for c in connections:
            print(*c)
