s = input()
n = len(s)
p = [0] * n
p[n-1] = n-1
for i in range(n-2, -1, -1):
    if (s[i] >= s[p[i+1]]):
        p[i] = i
    else:
        p[i] = p[i+1]
res, i = '', 0
while (i < n):
    res += s[p[i]]
    i = p[i]+1
print(res)
