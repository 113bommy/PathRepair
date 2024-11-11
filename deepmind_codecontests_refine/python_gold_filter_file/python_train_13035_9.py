def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return [str(x) for x in stdin.readline().split()]


from sys import stdin
from bisect import *

for i in range(int(input())):
    n, s, k = arr_inp(1)
    a = sorted(arr_inp(1))

    if s not in a:
        print(0)
    elif len(a) == 1 or s < a[0] - 1 or s > a[-1] + 1 or (a[0] == s and s > 1) or (a[-1] == s and s < n):
        print(1)
    else:

        ix, ans = bisect_left(a, s), []
        c1 = 1
        for i in range(ix + 1, k):
            if a[i] > c1 + s:
                ans.append(s + c1)
                break
            c1 += 1

        c1 = 1
        for i in range(ix - 1, -1, -1):
            if a[i] < s - c1:
                ans.append(s - c1)
                break
            c1 += 1

        if a[0] > 1 and a[0] != s:
            ans.append(a[0] - 1)
        if a[-1] < n and a[-1] != s:
            ans.append(a[-1] + 1)

        mi = float('inf')
        # print(ans)
        for i in ans:
            mi = min(mi, abs(i - s))

        print(mi)
