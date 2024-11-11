n = int(input())


def dfs(s):
    if int(s) > n:
        return 0
    ret = 1 if all([s.count(w) > 0 for w in '753']) else 0

    for x in '753':
        ret += dfs(s + x)
    return ret


print(dfs('0'))
