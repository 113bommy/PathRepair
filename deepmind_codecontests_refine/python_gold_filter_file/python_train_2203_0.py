def fk(n, l1, k):
    if (k==0):
        return str(l1[0])
    mi = l1[-1] - l1[0]
    p = (l1[-1] + l1[0]) >> 1
    for i in range(n-k):
        if (l1[i+k]-l1[i] < mi):
            mi = l1[i+k]-l1[i]
            p = (l1[i+k] + l1[i]) >> 1
    return str(p)

t = int(input())
l = []
for _ in range(t):
    n, k = list(map(int, input().split()))
    l1 = list(map(int, input().split()))
    l.append(fk(n, l1, k))
print('\n'.join(l))