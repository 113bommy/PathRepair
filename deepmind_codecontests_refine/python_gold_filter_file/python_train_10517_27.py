def solve(m, f, r):
    if (m == -1 or f == -1) or m + f < 30:
        return "F"
    for a, b in ((80, "A"), (65, "B"), (50, "C")):
        if m + f >= a:
            return b
    if r >= 50:
        return "C"
    return "D"
while True:
    m, f, r = map(int, input().split())
    if m == f == r == -1:
        break
    print(solve(m, f, r))
