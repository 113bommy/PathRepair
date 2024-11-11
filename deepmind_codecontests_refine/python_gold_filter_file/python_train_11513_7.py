n, k = map(int, input().split())
l = []
w = []
for i in range(k):
    l.append(chr(97 + i))
for i in range(n):
    w.append("".join(l))
q = "".join(w)
print(q[:n])


