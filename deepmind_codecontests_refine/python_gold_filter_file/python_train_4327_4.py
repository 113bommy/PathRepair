x,y=map(int,input().split())
t=0
ba=y
bb=y
bc=y
while True:
    if (ba >= x and bb >= x and bc >= x):
        print(t)
        break
    t+=1
    if t%3==1:
        ba = bb + bc - 1
    if t % 3 == 2:
        bb = ba + bc - 1
    if t%3==0:
        bc = ba + bb - 1
