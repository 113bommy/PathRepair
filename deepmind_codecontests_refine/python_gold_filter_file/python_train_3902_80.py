inp = input().split()
r = int(inp[0])
c = int(inp[1])
lines = 0
alt = 0
a = ''
b = ''
d = ''
ls1 = []
ls2 = []
for items in range(2,r,4):
    ls1.append(items)

for items in range(4,r,4):
    ls2.append(items)

for i in range(0,c):
    a += '#'
for i in range(0,c):
    if(i == c-1):
        b += '#'
    else:
        b += '.'
for i in range(0,c):
    if(i == 0):
        d += '#'
    else:
        d += '.'

for itm in range(1,r+1):
    if(itm == 1 or itm % 2 != 0):
        print(a)
    else:
        if(itm in ls1):
            print(b)
        else:
            print(d)
            


