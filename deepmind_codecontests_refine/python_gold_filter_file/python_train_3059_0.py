def f(n):
    m = 1
    for i in range(1,p-1):
        m = (m*n)%p
        if (m-1)%p:
            pass
        else:
            return False
    if (m*n-1)%p:
        return False
    return True
p = int(input())
ans = 0
for i in range(1,p):
    if f(i):
        ans += 1
print(ans)