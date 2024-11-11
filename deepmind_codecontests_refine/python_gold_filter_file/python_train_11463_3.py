A, B = map(int, input().split())
s = A + B
c = 0
k = 0
while c <= s:
    k += 1
    c += k
k-=1
n = list()
m = list()

if A < B:
    while k:
        if A >= k:
            n.append(k)
            A -= k
        else:
            m.append(k)
        k -= 1
else:
    while k:
        if B >= k:
            m.append(k)
            B -= k
        else:
            n.append(k)
        k -= 1
print(len(n))
print(*n)
print(len(m))
print(*m)