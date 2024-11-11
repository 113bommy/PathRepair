def rs(): return input().strip()
def ri(): return int(input())
def ria(): return list(map(int, input().split()))
def ia_to_s(a): return ' '.join([str(s) for s in a])


def solve(n, t):
    i = 0
    ans = 2

    while i < n:
        cl = t[i]
        j = i
        while j < n and t[j] == cl:
            j += 1
        left = j - i
        right = 0
        if j < n:
            cr = t[j]
            while j < n and t[j] == cr:
                j += 1
            right = j - i - left
        ans = max(ans, 2*min(left, right))
        i += left

    return ans


def main():
    n = ri()
    t = ria()
    print(solve(n, t))


if __name__ == '__main__':
    main()
