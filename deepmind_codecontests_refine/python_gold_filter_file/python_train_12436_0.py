def z(s):
    n = len(s)

    l, r = 0, 0
    z = [0] * n
    for i in range(1, n):
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1

    return z


def get_num_patterns(pat, arr):
    s = pat + [0.1] + arr
    z_arr = z(s)
    num = 0
    ln_pat = len(pat)
    for el in z_arr:
        if el == ln_pat:
            num += 1
    return num


def diff_arr(arr):
    diff = []
    for i in range(len(arr) - 1):
        diff.append(arr[i] - arr[i + 1])
    return diff


n, w = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
if w == 1:
    print(n)
else:
    a = diff_arr(a)
    b = diff_arr(b)
    print(get_num_patterns(b, a))

