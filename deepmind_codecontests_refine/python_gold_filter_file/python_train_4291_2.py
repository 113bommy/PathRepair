n = int(input())
s = list(input())


def DP_(color1, color2):
    DP = [[None for _ in range(2)] for _ in range(len(s))]
    DP[-1][0] = 0 if s[-1] == color1 else 10 ** 10
    DP[-1][1] = 0 if s[-1] == color2 else 10 ** 10
    parents = {}

    for i in range(len(s) - 2, -1, -1):
        DP[i][0] = DP[i + 1][0] if s[i] == color1 else DP[i + 1][1] + 1
        DP[i][1] = DP[i + 1][0] if s[i] == color2 else DP[i + 1][1] + 1
        parents[(i, 0)] = (i + 1, 0, "F") if s[i] == color1 else (i + 1, 1, "T")
        parents[(i, 1)] = (i + 1, 0, "F") if s[i] == color2 else (i + 1, 1, "T")

    return DP, parents


def print_solution(parents_dict):
    current = (0, 0)
    changed = []
    for i in range(len(s)):
        a, b, c = parents_dict[current]
        current = (a, b)
        if c == "T":
            changed.append(i)
        if a == len(s) - 1:
            break
    return changed


DP1, parents1 = DP_("W", "B")
DP2, parents2 = DP_("B", "W")

if DP1[0][0] < 10 ** 9:
    print(DP1[0][0])
    print(" ".join([str(x + 1) for x in print_solution(parents1)]))
elif DP2[0][0] < 10 ** 9:
    print(DP2[0][0])
    print(" ".join([str(x + 1) for x in print_solution(parents2)]))
else:
    print(-1)