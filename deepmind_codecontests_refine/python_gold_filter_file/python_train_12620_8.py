N = int(input())
X = list(map(int, input().split()))
mxr = (0, 0)
for i in range(N):
    I = i
    r = X[i]
    b = r
    while i > 0:
        i -= 1
        b = min(X[i], b)
        r += b
    i = I
    b = X[i]
    while i < N-1:
        i += 1
        b = min(X[i], b)
        r += b
    if r > mxr[0]:
        mxr = (r, I)

I = mxr[1]
i = I
rs = [0]*N
rs[i] = X[i]
b = rs[i]
while i > 0:
    i -= 1
    b = min(X[i], b)
    rs[i] = b
i = I
b = X[i]
while i < N-1:
    i += 1
    b = min(X[i], b)
    rs[i] = b
print(*rs)
