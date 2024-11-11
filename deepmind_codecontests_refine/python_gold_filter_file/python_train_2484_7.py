def solve(n, a):
    """
    References
    ----------
    [1]. 足跡-sokuseki-, CODE FESTIVAL 2016 Grand Final C - Cheating Nim, http://wk1080id.hatenablog.com/entry/2018/08/17/234023
    [2]. iroiro, CODE FESTIVAL 2016 Grand Final C - Cheating Nim, http://xxxasdfghjk999.hatenablog.jp/entry/2018/11/01/235259
    [3]. Yang33, 競プロにおけるNim、Grundy数とNimK, http://yang33-kassa.hatenablog.com/entry/2017/12/21/202812
    """
    x = 0
    for i in range(n):
        x ^= a[i]
    b = [a[i] ^ (a[i] - 1) for i in range(n)]
    mapping = {2**k-1: 0 for k in range(31)}
    for y in b:
        mapping[y] += 1
    ans = 0
    for k in range(30, 0, -1):
        y = 2**k - 1
        z = 2**(k-1)
        if (x & z) > 0 and (mapping[y] > 0):
            ans += 1
            mapping[y] -= 1
            x ^= y
    return ans if x == 0 else -1

n = int(input())
a = [int(input()) for i in range(n)]
print(solve(n, a))

