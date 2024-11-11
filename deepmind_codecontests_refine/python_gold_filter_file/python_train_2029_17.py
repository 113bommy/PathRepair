s = input()

AB = list()
BA = list()

i = 0

while s.find("AB", i, len(s)) != -1:
    AB.append(s.find("AB", i, len(s)))
    i = s.find("AB", i, len(s)) + 1

i = 0

while s.find("BA", i, len(s)) != -1:
    BA.append(s.find("BA", i, len(s)))
    i = s.find("BA", i, len(s)) + 1

if AB and BA:
    for a in AB:
        for b in BA:
            if abs(a - b) >= 2:
                print("YES")
                exit()
print("NO")