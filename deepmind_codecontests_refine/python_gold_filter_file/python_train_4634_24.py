w = input()
h = "hello"

c = 0
f = False
for l in w:
    if l == h[c]:
        c += 1
    if c == 5:
        print("YES")
        f = True
        break
if not f:
    print("NO")
