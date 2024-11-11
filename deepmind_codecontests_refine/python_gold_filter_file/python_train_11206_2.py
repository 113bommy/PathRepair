def first_fail(n):
    assert n >= 2
    was = set()
    for k in range(1, n + 1):
        mod = n % k
        if mod in was:
            return k
        was.add(mod)
    assert False, n

def solve(n, k):
    if n == 1:
        return k <= 2
    return k < first_fail(n)

n, k = [int(v) for v in input().split()]
print(["No", "Yes"][solve(n, k)])
