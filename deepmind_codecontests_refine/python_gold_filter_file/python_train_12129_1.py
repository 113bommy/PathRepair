v = int(input())

row1Line = input()
row2Line = input()
inRowLine = input()

row1 = row1Line.split()
row2 = row2Line.split()
inRow = inRowLine.split()

row1 = [int(row1[i]) for i in range(v-1)]
row2 = [int(row2[i]) for i in range(v-1)]
inRow = [int(inRow[i]) for i in range(v)]

ansList = []

for i in range(v):
    a = 0
    for j in range(i):
        a += row1[j]
    a += inRow[i]
    for j in range(i,v-1):
        a+= row2[j]
    ansList.append(a)
ansList.sort()
print(ansList[0] + ansList[1])
