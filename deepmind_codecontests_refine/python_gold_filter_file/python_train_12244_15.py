def fu():
    n, k = map(int, input().split())
    s = str(input())
    a = [0] * 26
    for i in s:
        a[ord(i) - 97] += 1
    m = 0
    for i in range(26):
        if a[i] > k:
            m = 5
            return print('NO')
    if m != 5:
        return print('YES')

fu()