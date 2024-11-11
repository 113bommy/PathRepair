R = lambda: map(int, input().split())
input()
a = list(R())
def f():
    y = 0
    for u, v, w in zip(R(), a, a[1:]):
        x = min(v - y, u)
        y = min(w, u - x)
        yield x + y
print(sum(f()))
