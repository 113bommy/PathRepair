j = int(input());



# j < - - Number of test cases.
# q < - - Lectures attended.
# w < - - Practical classes attended.
# l < - - Number of writes with only one pen.
# r < - - Number of writes with only one pencil.
# t < - - Pencil case capacity.xx

returnList = []

while(j>0):
    e = input()
    q,w,l,r,t = e.split()

    counterX = 0
    counterY = 0


    z = int(q) // int(l)

    counterX += z

    p = int(w)//int(r)

    counterY += p

    if(int(q[-1]) != 0 and int(q)%int(l) != 0 or len(q) >= 1 and int(q)%int(l) != 0):
        counterX += 1
    if(int(w[-1]) != 0 and int(w)%int(r) != 0 or len(w) >= 1 and int(w)%int(r) != 0):
        counterY += 1

    if(counterX == 0):
        counterX += 1
    if counterY == 0:
        counterY += 1
    if(counterX + counterY > int(t)):
        returnList.append(str(-1))
        j-=1
        continue

    returnList.append([str(counterX),str(counterY)])
    j-=1

for x in returnList:
    if x == "-1":
        print("-1")

    else:
        print(' '.join(x))
