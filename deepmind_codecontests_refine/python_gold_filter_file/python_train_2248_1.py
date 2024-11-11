def solve():
    k = int(input())
    s = input()
    s = s.replace('-',' ')
    x = [len(a) for a in s.split(' ')]
    x[-1] -= 1
    x = x[::-1]

    def good(z):
        y = x[:]
        l = 1
        curr = 0
        while y:
            u = y.pop() + 1
            if u > z:
                return False
            elif curr + u > z:
                l += 1
                curr = u
            else:
                curr += u
        return l <= k

    low, high = 0, 10**6 + 1
    while high - low > 1:
        m = (low + high) // 2
        if good(m):
            high = m
        else:
            low = m
    return high

print(solve())

