n, m, q = map(int, input().split())
s = input()
t = input()
pat = [0] * n
i = 0
c = 0
while True:
    f = s[i:].find(t)
    if f == -1:
        for j in range(i, n):
            pat[j] = c
        break
    g = i + f
    for j in range(i, g):
        pat[j] = c
    c += 1
    pat[g] = c
    i = g + 1

pat = [0] + pat
for _ in range(q):
    l, r = map(int, input().split())
    if r - l + 1 >= m:
        print(pat[r-m+1] - pat[l-1])
    else:
        print(0)
