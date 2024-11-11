#region bcf
# code section by Barry Fam
#
# pylint: disable= reimported
#region logsearch.py
import math as m


def binary_search_int(f, start, stop):
    """
    Binary search for the point at which f() becomes false

    f() may be evaluated at the points in [start, stop) half-open
    The return value will be in the range [start, stop] inclusive

    f() must be always true to the left of some point, and always false to the right

    >>> f = lambda x: x <= 50
    >>> binary_search_int(f, 40, 91)
    51
    >>> binary_search_int(f, 20, 31)
    31
    >>> binary_search_int(f, 60, 81)
    60
    """
    assert start < stop

    left, right = start, stop
    while left < right:
        mid = (left + right)//2
        if f(mid):
            left = mid+1
        else:
            right = mid

    return right


def binary_search_float(f, left, right, rel_tol=1e-09, abs_tol=0.0):
    """
    Binary search for the point at which f() becomes false

    f() must be always true to the left of some point, and always false to the right

    Note: If the return may be close to 0, set abs_tol to avoid excessive/infinite iteration

    >>> f = lambda x: x < 3.5
    >>> _ = binary_search_float(f, 0, 10)
    >>> round(_, 6)
    3.5
    """
    assert left <= right

    while not m.isclose(left, right, rel_tol=rel_tol, abs_tol=abs_tol):
        mid = (left + right)/2
        if f(mid):
            left = mid
        else:
            right = mid

    return right


def ternary_search_int(f, start, stop):
    """
    Ternary search for the maximum point of f()

    f() must be strictly increasing to the left of some point, and strictly decreasing to the right

    >>> f = lambda x: -(x-42)**2
    >>> ternary_search_int(f, 0, 100)
    42
    """
    assert start < stop

    invphi2 = (3-m.sqrt(5)) / 2

    a, d = start, stop-1
    b = a + round(invphi2 * (d-a))
    c = b + m.ceil(invphi2 * (d-b))
    fb = f(b)
    fc = f(c)

    while True:
        if fb < fc:
            if c == d: return d
            a = b+1
            b, fb = c, fc
            c = b + m.ceil(invphi2 * (d-b))
            fc = f(c)
        else:
            if a == b: return a
            d = c-1
            c, fc = b, fb
            b = c - m.ceil(invphi2 * (c-a))
            fb = f(b)


def ternary_search_float(f, left, right, rel_tol=1e-09, abs_tol=0.0):
    """
    Ternary search for the maximum point of f()

    f() must be strictly increasing to the left of some point, and strictly decreasing to the right

    Note: If the return may be close to 0, set abs_tol to avoid excessive/infinite iteration

    >>> f = lambda x: -(x-3.5)**2
    >>> _ = ternary_search_float(f, 0, 10)
    >>> round(_, 6)
    3.5
    """
    assert left <= right

    invphi2 = (3-m.sqrt(5)) / 2

    a, d = left, right
    b = a + invphi2 * (d-a)
    c = b + invphi2 * (d-b)
    fb = f(b)
    fc = f(c)

    while not m.isclose(a, d, rel_tol=rel_tol, abs_tol=abs_tol):
        if fb < fc:
            a = b
            b, fb = c, fc
            c = b + invphi2 * (d-b)
            fc = f(c)
        else:
            d = c
            c, fc = b, fb
            b = c - invphi2 * (c-a)
            fb = f(b)

    return c


# if __name__ == "__main__":
if False:  # pylint: disable= using-constant-test
    import doctest
    doctest.testmod()

#endregion logsearch.py
#endregion bcf
###############################################################################

N,A,R,M = map(int, input().split())
h = list(map(int, input().split()))

def cost(final_h):
    cost = 0
    over = 0
    under = 0
    for orig_h in h:
        if orig_h < final_h: under += final_h - orig_h
        elif orig_h > final_h: over += orig_h - final_h

    if M < A+R:
        move = min(over, under)
        cost += M * move
        over -= move
        under -= move

    cost += over*R + under*A
    return -cost

x = ternary_search_int(cost, 0, int(1e9)+1)
print(-cost(x))
