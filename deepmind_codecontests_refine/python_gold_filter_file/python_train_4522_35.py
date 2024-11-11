s = input()
t = input()
letter = "abcdefgh"
s1 = letter.index(s[0])
t1 = letter.index(t[0])
s2 = int(s[1])
t2 = int(t[1])
i = 0
while s1 != t1 or s2 != t2:
    locals()["move"+str(i)] = ""
    if s1 < t1:
        locals()["move"+str(i)] += "R"
        s1 += 1
    elif s1 > t1:
        locals()["move" + str(i)] += "L"
        s1 += -1
    if s2 < t2:
        locals()["move" + str(i)] += "U"
        s2 += 1
    elif s2 > t2:
        locals()["move" + str(i)] += "D"
        s2 += -1
    i += 1
print(i)
for k in range(i):
    print(locals()["move" + str(k)] , end = "\n")