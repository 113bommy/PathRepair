n, a = int(input()), list(map(int, input().split()))
an, ap = sorted(x for x in a if x < 0), [x for x in a if x > 0]
if n > 1 and len(an) % 2:
    an.pop()
print(' '.join(map(str, ap + an)) if ap or an else 0)