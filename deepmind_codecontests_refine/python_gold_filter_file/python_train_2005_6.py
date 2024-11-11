def do(s, x):
    for i in range(x + 1):
        s[i] = (s[i] + 1)%2
    s = s[:i + 1][::-1] + s[i + 1:]
    return s
def solve(n, a, b):
    ans = []
    for i in range(n - 1, -1, -1):
        if(a[i] != b[i]):
            if(a[0] != b[i]):
                a = do(a, i)
                ans += [i + 1]
            else:
                a[0] = (a[0] + 1)%2
                a = do(a, i)
                ans += [1, i + 1]
    return [len(ans)] + ans
def main():
    t = int(input())
    for i in range(t):
        n, a, b = int(input()), [int(i) for i in input()], [int(i) for i in input()]
        print(*solve(n, a, b))
main()
