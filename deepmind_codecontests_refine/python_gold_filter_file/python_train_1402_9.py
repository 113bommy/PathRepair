"""http://codeforces.com/problemset/problem/483/A"""

def parse(st):
    return list(map(int, st.split()))

def solve(l, r):
    if l % 2 != 0:
        l += 1
    if l + 2 > r:
        return '-1'
    else:
        return '{} {} {}'.format(l, l + 1, l + 2)

if __name__ == '__main__':
    l, r = parse(input())
    res = solve(l, r)
    print(res)
