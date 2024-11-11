n = int(input())
a = list(map(int, input().split()))
cnt = 1
b = []
for i in range(1, n):
    if a[i] == a[i - 1]:
        cnt += 1
    else:
        b.append(cnt)
        cnt = 1
b.append(cnt)
ans = 0
for i in range(1, len(b)):
    ans = max(ans, min(b[i], b[i - 1]))
print(ans * 2)