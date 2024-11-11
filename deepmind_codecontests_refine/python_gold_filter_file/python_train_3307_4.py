n = int(input())
a = list(map(int, input().strip().split()))

amin = min(a)
for i in range(n):
    a[i] -= amin
ans = amin % n
cnt = 0
while True:
    if a[ans] <= cnt:
        break
    ans = (ans + 1) % n
    cnt += 1
print(ans + 1)

