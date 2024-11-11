import sys
a = int(sys.stdin.readline())
s = sys.stdin.readline().strip()

s1 = s[0]
s2 = ''
p = ''
f = False
for i in s:
    if i >= s1[-1]:
        s1 += i
        p += '0'
    elif not s2 or i >= s2[-1]:
        s2 += i
        p += '1'
    else:
        print("NO")
        f = True
        break
if not f:
    print("YES")
    print(p)