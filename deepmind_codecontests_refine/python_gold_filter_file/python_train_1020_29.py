N = int(input())


def dfs(s):
    if int(s) > N:
        return 0
    ret = 1 if all(s.count(c) > 0 for c in '357') else 0
    for c in '357':
        ret += dfs(s + c)
    return ret


print(dfs('0'))
