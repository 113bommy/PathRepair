H, W, N = map(int, input().split())
A = []
L = 0
ans = [0] * 10

for i in range(N):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    for i in range(max(0, a - 2), min(a + 1,H-2)):
        for j in range(max(0, b - 2), min(b + 1,W-2)):
            A.append((i, j))
            L += 1

A.sort()
count = 1
for i in range(L - 1):
    if A[i] == A[i + 1]:
        count += 1
    else:
        ans[count] += 1
        count = 1
if L >= 1:
    ans[count] += 1

ans[0] = (H - 2) * (W - 2) - sum(ans)

for i in range(10):
    print(ans[i])