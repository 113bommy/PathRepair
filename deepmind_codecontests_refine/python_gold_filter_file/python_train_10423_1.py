n = int(input())
s = str(input())
X = []
cur = s[0]
cnt = 0
ans = 0
for i in range(n):
    if s[i] == cur:
        cnt += 1
    else:
        if cur == 'G':
            ans = max(cnt, ans)
        X.append((cnt, cur))
        cur = s[i]
        cnt = 1
else:
    if cur == 'G':
        ans = max(cnt, ans)
    X.append((cnt, cur))

m = len(X)

if m <= 2:
    print(ans)
    exit()

for i, (cnt, c) in enumerate(X):
    if c == 'G':
        continue
    if cnt == 1:
        if i != 0 and i != m-1:
            if i-3 >= 0 or i+3 <= m-1:
                ans = max(ans, X[i-1][0]+1+X[i+1][0])
            else:
                ans = max(ans, X[i-1][0]+X[i+1][0])
        elif i == 0:
            if i+3 <= m-1:
                ans = max(ans, 1+X[i+1][0])
            else:
                ans = max(ans, X[i+1][0])
        else:
            if i-3 >= 0:
                ans = max(ans, X[i-1][0])
            else:
                ans = max(ans, X[i-1][0])
    else:
        if i != 0 and i != m-1:
            ans = max(ans, max(1+X[i-1][0], 1+X[i+1][0]))
        elif i == 0:
            if i+3 <= m-1:
                ans = max(ans, 1+X[i+1][0])
            else:
                ans = max(ans, X[i+1][0])
        else:
            if i-3 >= 0:
                ans = max(ans, X[i-1][0]+1)
            else:
                ans = max(ans, X[i-1][0])
print(ans)
