def main():
    def f(n):
        m = int(n ** 0.5) + 1
        t = [1] * (n + 1)
        for i in range(3, m):
            if t[i]: t[i * i :: 2 * i] = [0] * ((n - i * i) // (2 * i) + 1)
        return [2] + [i for i in range(3, n + 1, 2) if t[i]]

    a, b, k = map(int, input().split())
    n = 1100001
    
    t, p, x = [-1] * n, f(n), -1
    k -= 1; b += 1

    for i in range(len(p) - k):
        t[p[i]] = p[i + k] - p[i]
    for i in range(1,n):
        if t[-i] < 0:
            t[-i] = t[-i + 1] + 1
    for i in range(a + 1, b):
        t[i] = max(t[i], t[i - 1])
    for l in range(1, b - a + 1):
        if t[b - l] < l:
            x = l
            break
    print(x)
main()