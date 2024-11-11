def f(s):
    ans = []
    for i in range(len(s)):
        ans.append(int(s[i]))
    return sorted(ans)

n = int(input())
sh = f(input())
m = f(input())
g = m.copy()

for i in range(n):
    for j in range(len(m)):
        if m[j] >= sh[i]:
            m = m[j+1:]
            break
    else:
        print(n - i)
        break
else:
    print(0)

m = g.copy()
for i in range(n):
    for j in range(len(m)):
        if m[j] > sh[i]:
            m = m[j+1:]
            break
    else:
        print(i)
        break
else:
    print(n)