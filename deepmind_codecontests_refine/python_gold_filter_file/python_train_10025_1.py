def solve():
    n, d = input().split()
    n = int(n)
    d = int(d)
    xd = input().split()
    xd1 = []
    for i in xd:
        xd1.append(int(i))
    xd1.sort()
    if int(xd1[-1]) <= d or int(xd1[0]) + int(xd1[1]) <= d:
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        solve()