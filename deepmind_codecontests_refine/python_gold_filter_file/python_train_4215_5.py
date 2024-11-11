n = int(input())
s = [input() for i in range(n)]
f = [[0 for i in range(26)] for j in range(26)]
for i in range(n):
    for k in range(i + 1, n):
        if len(s[k]) < len(s[i]) and s[k] == s[i][:len(s[k])]:
            print('Impossible')
            exit(0)
        for j in range(min(len(s[k]), len(s[i]))):
            if s[k][j] != s[i][j]:
                if f[ord(s[k][j]) - ord('a')][ord(s[i][j]) - ord('a')] == 1:
                    print('Impossible')
                    exit(0)
                if f[ord(s[i][j]) - ord('a')][ord(s[k][j]) - ord('a')] == -1:
                    print('Impossible')
                    exit(0)
                f[ord(s[k][j]) - ord('a')][ord(s[i][j]) - ord('a')] = -1
                f[ord(s[i][j]) - ord('a')][ord(s[k][j]) - ord('a')] = 1
                break

def dfs(k, used, f, res):
    if used[k] == 1:
        print('Impossible')
        exit(0)
    used[k] = 1
    for i in range(26):
        if used[i] != 2 and f[k][i] == 1:
            dfs(i, used, f, res)
    used[k] = 2
    res.append(k)

used = [0 for i in range(26)]
res = []
for i in range(25, -1, -1):
    if used[i] == 0:
        dfs(i, used, f, res)
for i in range(26):
    print(chr(res[25 - i] + ord('a')), end='')
            
