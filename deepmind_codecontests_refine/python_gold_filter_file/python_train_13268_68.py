n = int(input())
p = []
q = []
for x in range(n):
    a, b = input().split(" ")
    p.append(int(a))
    q.append(int(b))
x = 0
c = 0
for x in range(n):
    if p[x]<=q[x]-2:
        c += 1
print(c)
