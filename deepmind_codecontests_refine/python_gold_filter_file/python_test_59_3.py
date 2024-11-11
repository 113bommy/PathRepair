def solve(n, prefs):
    h = n // 2
    for d1 in range(5):
        for d2 in range(d1+1, 5):
            d1c = 0
            d2c = 0
            both = 0
            for p in prefs:
                if p[d1] == 1 and p[d2] == 1:
                    both += 1
                elif p[d1] == 1:
                    d1c += 1
                elif p[d2] == 1:
                    d2c += 1

            if d1c > h or d2c > h:
                continue

            if d1c == h and d2c == h:
                return "YES"

            rem = n - d1c - d2c
            if both >= rem:
                return "YES"
    return "NO"


t = int(input().strip())
inputs = []
for _ in range(t):
    n = int(input().strip())
    prefs = []
    for _ in range(n):
        p = list(map(int, input().strip().split()))
        prefs.append(p)
    inputs.append((n, prefs))

for n, prefs in inputs:
    print(solve(n, prefs))
