def ii():
    return int(input())
def mi():
    return map(int, input().split())
def li():
    return list(mi())

n = ii()
s = input().strip()
a = [0] * (n + 1)
m = [0] * (n + 1)
for i in range(n):
    a[i] = a[i - 1] + (1 if s[i] == '(' else -1)
    m[i] = min(m[i - 1], a[i])

ans = 0
mm = a[n - 1]
for j in range(n - 1, -1, -1):
    mm = min(mm, a[j])
    if s[j] == '(':
        if a[n - 1] == 2 and mm == 2 and m[j - 1] >= 0:
            ans += 1
    else:
        if a[n - 1] == -2 and mm == -2 and m[j - 1] >= 0:
            ans += 1

print(ans)
