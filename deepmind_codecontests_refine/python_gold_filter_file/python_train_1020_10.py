n = int(input())
def dfs(s):
    if int(s)>n:
        return 0
    res = 1 if all(s.count(c) > 0 for c in '753') else 0
    for i in '753':
        res += dfs(s+i)
    return res
print(dfs('0'))
