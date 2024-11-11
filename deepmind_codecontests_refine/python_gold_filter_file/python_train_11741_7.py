n = int(input())
a = list(map(int, input().split()))

now = 1
allows = []
for i in range(n):
    ha = a[i]
    if ha > now:
        print(-1)
        exit()
    allows.append(now - ha)
    now = (now - ha) * 2
if now < a[n]:
    print(-1)
    exit()
result = a[n]
now = a[n]
for i in range(n):
    if now > allows[n-1-i]:
        now = allows[n-1-i]
    now = now + a[n-1-i]
    result += now
print(result)