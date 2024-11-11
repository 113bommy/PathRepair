# https://codeforces.com/contest/1375/problem/B

"""
You have a grid with n rows and m columns.
Every cell has a non-negative integer on it.

We say that a grid is good if for every cell the following holds:
    * If its value is 0 then we don't mind
    * If its value is k > 0 then we require that exactly k of its neighbours
    have a number greater than 0. (We say cells are neighbouring if they share an edge)

You are allowed to increment any cell's value by 1 as many times as you want.

First remark the following:
    * If you see > 2 on the corners then it is impossible
    * If you see > 3 on the edges then it is impossible
    * If you see >4 anywhere then it is impossible

If none of this holds then we know that it is always possible by adding 1 to everything until we get
2 3 ... 3 2
3 4 ... 4 3
. ....... .
3 4 ... 4 3
2 3 ... 3 2

This solution has complexity O(n*m)
"""


def answer():
    n, m = map(int, input().split())

    a = []
    for i in range(n):
        a.append(list(map(int, input().split())))

    # Check the corners:
    for i in [0, n - 1]:
        for j in [0, m - 1]:
            if a[i][j] > 2:
                print('NO')
                return

    # Check the horizontal edges
    for i in [0, n-1]:
        for j in range(1, m-1):
            if a[i][j] > 3:
                print('NO')
                return

    # Check the vertical edges
    for j in [0, m-1]:
        for i in range(1, n-1):
            if a[i][j] > 3:
                print('NO')
                return

    # Check everywhere else
    for i in range(1, n-1):
        for j in range(1, m-1):
            if a[i][j] > 4:
                print('NO')
                return

    print('YES')
    print('2 ' + '3 '*(m-2) + '2')
    for _ in range(n-2):
        print('3 ' + '4 '*(m-2) + '3')
    print('2 ' + '3 ' * (m - 2) + '2')

    return


# Number of test cases
t = int(input())

for _ in range(t):
    answer()



