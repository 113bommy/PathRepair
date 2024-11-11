tml = input().split()
sl = int(tml[0])
tl = int(tml[1])
s = input()
t = input()

li = list()
count = sl
for tn in range(tl - sl + 1):
    tmpC = 0
    tmpA = list()
    tmp = t[tn:tn + sl]
    for i in range(sl):
        if s[i] != tmp[i]:
            tmpC += 1
            tmpA.append(str(i + 1))
    if tmpC <= count:
        count = tmpC
        li = tmpA
        if count == 0:
            break
print(count)
print(" ".join(li))