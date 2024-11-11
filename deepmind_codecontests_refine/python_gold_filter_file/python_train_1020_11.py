N = int(input())
 
def dfs(s):
    if int(s) > N:
        return 0
    r = 1 if all([i in s for i in '357']) else 0
    for c in '357':
        r += dfs(s+c)
    return r

print(dfs('0'))