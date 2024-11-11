import pprint

n, m = map(int, input().split())
s = input()
t = input()

ans = 0

X = s
Y = t
m = len(X)
n = len(Y)
L = [[0]*(n + 1) for i in range(m + 1)]
i = 1
j = 1
while i < m + 1:
    j = 1
    while j < n + 1:
        v = 0
        if X[i-1] == Y[j-1]:
            v = max(L[i - 1][j - 1] + 2, 2)

        if L[i][j - 1] > v:
            v = L[i][j - 1] - 1
        if L[i - 1][j] > v:
            v = L[i - 1][j] - 1
        L[i][j] = v
        if v > ans:
            ans = v
        j += 1
    i += 1

print(ans)


