n = int(input())
b = n
k = 1
q = 0
d = []
while b >= 10:
    b = b // 10
    k += 1
z = 9 * k
s = 0
if n - z < 0:
    z = n
for i in range(n-z,n):
    s = 0
    for j in range(len(str(i))):
        s += int((str(i))[j])
    if i + s  == n:
        q += 1
        d.append(i)
print(q)
for i in range(q):
    print(d[i])