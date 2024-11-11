from itertools import accumulate


def solve(s, t):
    IMP = "---"

    if s < t:
        return s

    n = len(s)
    next_smallest = [None for _ in range(n + 1)]
    for i, c in enumerate(s[::-1]):
        prev = next_smallest[n - i]
        if prev is None or c < prev[0]:
            best = (c, n - i - 1)
        else:
            best = prev
        next_smallest[n - i - 1] = best

    next_smallest.pop()

    # Try all swaps and see if one works
    for i, a in enumerate(s):
        if i == n - 1:
            continue

        s2 = list(s)
        b, ind = next_smallest[i + 1]
        s2[i], s2[ind] = s2[ind], s2[i]
        s2 = "".join(s2)
        
        if s2 < t:
            return s2

    return IMP


for _ in range(int(input())):
    s, t = input().split()
    print(solve(s, t))