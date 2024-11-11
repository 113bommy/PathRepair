c = []
cT = 0
isE = True
for n in range(int(input())):
    c.append(list(map(int, input().split())))
for i in range(3):
    for l in range(len(c)):
        cT += c[l][i]
    if cT == 0:
        cT = 0
    else:
        isE = False
        break
if isE:
    print("YES")
else:
    print("NO")