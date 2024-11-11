s1 = input()
s2 = input()

start = (8 - (ord(s1[1]) -ord('0')), ord(s1[0]) - ord('a'))
end = (8 - (ord(s2[1]) - ord('0')), ord(s2[0]) - ord('a'))


x = end[0] - start[0]
y = end[1] - start[1]
step = max(abs(x), abs(y))
print(step)
a = min(abs(x), abs(y))
if x >= 0 and y >= 0:
    for i in range(0, a):
        print("RD")
elif x >= 0 and y <= 0:
    for i in range(0, a):
        print("LD")
elif x <= 0 and y >= 0:
    for i in range(0, a):
        print("RU")
elif x <= 0 and y <= 0:
    for i in range(0, a):
        print("LU")

if abs(x) != a:
    b = abs(x) - a
    if x >= 0:
        for i in range(0, b):
            print("D")
    else:
        for i in range(0, b):
            print("U")
else:
    b = abs(y) - a
    if y >= 0:
        for i in range(0, b):
            print("R")
    else:
        for i in range(0, b):
            print("L")





# print(start, end)