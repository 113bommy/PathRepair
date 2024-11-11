num=[int(x)-1 for x in input().split()]
mapp=[[0]*50 for i in range(50)]
for i in range(50):
    for j in range(50):
        r=0
        if i>=25:
            r+=1
        c=0
        if j>=25:
            c+=1
        mapp[i][j]=r*2+c

x=1
y=1
for i in range(num[1]):
    mapp[x][y]=1
    y+=2
    if y>=24:
        x+=2
        y=1

x = 1
y = 26
for i in range(num[0]):
    mapp[x][y] = 0
    y += 2
    if y >= 49:
        x += 2
        y = 26

x = 26
y = 1
for i in range(num[3]):
    mapp[x][y] = 3
    y += 2
    if y >= 24:
        x += 2
        y = 1

x = 26
y = 26
for i in range(num[2]):
    mapp[x][y] = 2
    y += 2
    if y >= 49:
        x += 2
        y = 26
print(50,50)
for i in range(50):
    for j in range(50):
        print(chr(ord('A')+mapp[i][j]),end='')
    print()
