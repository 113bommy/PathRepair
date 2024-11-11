n, T = map(int, input().split())
a = [*map(int, input().split())]
t = [*map(int, input().split())]
l = sorted(zip(t, a))


S = sum(x * y for x, y in l)
V = sum(a)
while l and S > V * T and l[-1][0] > T:
    x, y = l.pop()
    d = min(y, (S - V * T) / (x - T))
    S -= x * d
    V -= d

l.reverse()
while l and V * T > S and l[-1][0] < T:
    x, y = l.pop()
    d = min(y, (V * T - S) / (T - x))
    S -= x * d
    V -= d

print(round(V, 7) if S == V * T else 0)