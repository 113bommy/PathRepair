def solve():
    can_positive = False
    if len(p) > 0:
        if k<n:
            can_positive = True
        else:
            can_positive = len(m) % 2 == 0
    else:
        can_positive=k%2==0
    if not can_positive:
        m.sort(reverse=True)
        return m[:k]+p
    p.sort()
    m.sort(reverse=True)
    a = [p.pop()] if k % 2 else [1]
    while len(p) >= 2:
        a.append(p.pop()*p.pop())
    while len(m) >= 2:
        a.append(m.pop()*m.pop())
    return a[:1] + sorted(a[1:], reverse=True)[:(k-k%2)//2]

mod = 10**9+7
n, k = list(map(int, input().split()))
m, p = [], []
for i in map(int, input().split()):
    if i < 0:
        m.append(i)
    else:
        p.append(i)
ans = 1
for i in solve():
    ans = ans * i % mod
print(ans)