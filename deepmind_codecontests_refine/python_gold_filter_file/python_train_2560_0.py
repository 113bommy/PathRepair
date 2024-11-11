n, w = map(int, input().split())
arr = list(map(float, input().split()))
r = sorted(list(range(n)), key=lambda x: arr[x])
ans = [0] * n
for i in r:
    crt = int((arr[i] + 1) // 2)
    ans[i] += crt
    w -= crt
if w < 0:
    print(-1)
    exit(0)

for i in reversed(r):
    crt = int(min(w, arr[i] - ans[i]))
    w -= crt
    ans[i] += crt
    if w == 0:
        break

print(' '.join(map(str, ans)))
