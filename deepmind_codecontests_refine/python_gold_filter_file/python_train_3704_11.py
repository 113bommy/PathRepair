code = input()
b = 96
res = True
for k in code:
    if ord(k) > b + 1:
        res = False
    elif ord(k) == b + 1:
        b += 1
if res:
    print("YES")
else:
    print("NO")
