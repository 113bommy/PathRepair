p = input()
a = input()
d = "qwertyuiopasdfghjkl;zxcvbnm,./"
ans = ""
if p == "R":
    for i in a:
        w = d.index(i) - 1
        ans += d[w]
else:
    for i in a:
        w = d.index(i) + 1
        ans += d[w]
print(ans)
