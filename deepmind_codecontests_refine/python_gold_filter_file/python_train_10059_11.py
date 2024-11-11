s = input()
n = len(s)
a = [0]
b = [0]
for x in s:
    if x == "a":
        a.append(a[-1] + 1)
        b.append(b[-1])
    else:
        a.append(a[-1])
        b.append(b[-1] + 1)
ans = 0
a.append(a[-1])
b.append(b[-1])
for i in range(1, n + 1):
    for j in range(i, n + 1):
        t = a[i] + b[j + 1] - b[i - 1] + a[-1] - a[j] # a's till i, then b from i to j, then a
        ans=max(ans,t)
print(ans)