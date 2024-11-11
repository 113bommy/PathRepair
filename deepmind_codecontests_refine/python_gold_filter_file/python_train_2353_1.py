n, k, q = map(int, input().split())
c = [0]*200003
p = [0]*200003
for i in range(n):
    a, b = map(int, input().split())
    p[a] += 1
    p[b+1] -= 1
for i in range(200003):
    p[i] += p[i-1]
    c[i] = c[i-1] + (p[i]>=k)
l = []
for i in range(q):
    a, b = map(int, input().split())
    l.append(c[b] - c[a-1])
print(*l, sep = '\n')