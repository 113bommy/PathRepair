


def factor(n):
    tmp = n
    i = 2
    result = []
    while i * i <= n:
        if tmp % i == 0:
            tmp //= i
            result += [i]
        else:
            i += 1

    if tmp != 1:
        result += [tmp]
    return result


n, k = map(int, input().split())

n_fac = factor(n)

if len(n_fac) < k:
    print(-1)
else:
    pre = n_fac[:k - 1]
    tmp = 1
    for j in n_fac[k - 1:]:
        tmp *= j
    pre += [tmp]
    print(' '.join(map(str, pre)))
