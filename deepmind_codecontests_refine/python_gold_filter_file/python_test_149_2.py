from sys import stdin, stdout
rd = lambda: list(map(int, stdin.readline().split()))
rds = lambda: stdin.readline().rstrip()
ii = lambda: int(stdin.readline())
INF = 1 << 62
mod = 10**9 + 7


def solve(s, k, x):
    s = s[::-1] 
    x -= 1

    res = []
    bs = []
    i = 0
    while i < len(s):
        if s[i] == 'a':
            res.append('a')
            i += 1
        else:
            curr = 0  # num of '*'
            while i < len(s) and s[i] != 'a':
                i += 1
                curr += 1

            # index in res, number of bs we can fit here
            bs.append((len(res), curr * k))
            res.append('_')
    
    # decode x
    for j, lim in bs:
        d = x % (lim+1)
        x //= (lim+1)
        res[j] = 'b' * d

    return ''.join(res)[::-1]


for _ in range(ii()):
    n, k, x = rd()
    s = rds()

    print(solve(s,k,x))

#stdout.write(' '.join(map(str, ar)))
#stdout.write(f'{res}')

