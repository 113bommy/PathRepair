n = int(input())
L = list(map(int, input().split()))
L.sort()
r = 1
c = L[0]
m = 1
p = 1
for i in range(1,n):
    if L[i] == c:
        p += 1
    else:
        m = max(m,p)
        p = 1
        c = L[i]
        r += 1
print(max(m,p),r)
