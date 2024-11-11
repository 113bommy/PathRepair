import re
st = "^CODEFORCES$"
a = input()
for i in range(1, len(st)):
    if re.match(st[:i] + ".*" + st[i:], a):
        print("YES")
        quit()
print("NO")

