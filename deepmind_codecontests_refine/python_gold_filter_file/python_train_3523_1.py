H, W = map(int, input().split())
N = int(input())
a = list(map(int, input().split()))
ans = []
for i in range(N):
    for _ in range(a[i]):
        ans.append(i+1)
for i in range(H):
    if i % 2:
        print(*(list(reversed(ans[i * W:(i + 1) * W]))))
    else:
        print(*ans[i * W:(i + 1) * W])
