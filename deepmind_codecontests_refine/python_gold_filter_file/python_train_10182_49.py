def solve(n, ga, sa, ba, gb, sb, bb):
    ans = n
    for g in range(1 if ga >= gb else n // ga + 1):
        n2 = n - g * ga
        tmp1 = g * gb
        if ba >= bb:
            s = n2 // sa
            ans = max(ans, n2 + tmp1, n2 - s * sa + tmp1 + s * sb)
        elif sa >= sb:
            b = n2 // ba
            ans = max(ans, n2 + tmp1, n2 - b * ba + tmp1 + b * bb)
        else:
            for s in range(n2 // sa + 1):
                b = (n2 - s * sa) // ba
                ans = max(ans, n2 - s * sa - b * ba + tmp1 + s * sb + b * bb)
    return ans


n = int(input())
ga, sa, ba = list(map(int, input().split()))
gb, sb, bb = list(map(int, input().split()))
n2 = solve(n, ga, sa, ba, gb, sb, bb)
n3 = solve(n2, gb, sb, bb, ga, sa, ba)
print(n3)
