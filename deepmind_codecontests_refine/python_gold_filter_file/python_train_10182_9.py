def solve(n, ga, sa, ba, gb, sb, bb):
    gd, sd, bd = gb - ga, sb - sa, bb - ba

    if bd <= 0:
        if sd <= 0:
            if gd <= 0:
                return n
            return n + n // ga * gd
        if gd <= 0:
            return n + n // sa * sd
        return max(n + g * gd + (n - g * ga) // sa * sd for g in range(n // ga + 1))
    if sd <= 0:
        if gd <= 0:
            return n + n // ba * bd
        return max(n + g * gd + (n - g * ga) // ba * bd for g in range(n // ga + 1))
    if gd <= 0:
        return max(n + s * sd + (n - s * sa) // ba * bd for s in range(n // sa + 1))
    (_, ga, gd), (_, sa, sd), (_, ba, bd) = \
        sorted([(gb / ga, -ga, gd), (sb / sa, -sa, sd), (bb / ba, -ba, bd)], reverse=True)
    ga, sa, ba = -ga, -sa, -ba
    sga = 0 if n // ga < 1000 else n // ga // 2
    return max(n + g * gd + s * sd + (n - g * ga - s * sa) // ba * bd
               for g in range(sga, n // ga + 1)
               for s in range((n - g * ga) // sa + 1))


n = int(input())
ga, sa, ba = list(map(int, input().split()))
gb, sb, bb = list(map(int, input().split()))
n2 = solve(n, ga, sa, ba, gb, sb, bb)
n3 = solve(n2, gb, sb, bb, ga, sa, ba)
print(n3)
