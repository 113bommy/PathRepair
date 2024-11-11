n = int(input())
s = input()
c1 = 0
c0 = 0
count = 0
b = True
for c in s:
    if c == "1":
        c1 += 1
        c0 = 0
        count += 1
    else:
        c0 += 1
        c1 = 0
    if (c0 > 2) or (c1 > 1) or ((count == 0) and (c0 > 1)):
        b = False
        break
if (c0 > 1) or (c1 > 1) or (count == 0):
    b = False
if b:
    print("Yes")
else:
    print("No")
