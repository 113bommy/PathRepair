a, m = map(int, input().split())
def f(x):
    for i in range(m):
        x = (2 * x) % m
        if not x: return 'Yes'
    return 'No'
print(f(a))