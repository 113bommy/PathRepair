(x, y, a, b, c), p, q, r = [map(int, o.split()) for o in open(0)]
print(sum(sorted(sorted(p)[-x:] + sorted(q)[-y:] + list(r))[-x-y:]))