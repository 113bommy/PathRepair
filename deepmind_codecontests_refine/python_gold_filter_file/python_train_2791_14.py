n,k = map(int,input().split())
h = list(map(int, input().split()))

cnt = [0]*n
for i in range(1, n):
    cnt[i] = min(abs(h[m]-h[i])+cnt[m] for m in range(max(0, i-k), i))
print(cnt[n - 1])
