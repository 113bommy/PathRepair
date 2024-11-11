def turn(blocks, frc, toc):
    res=[]
    for i in range(len(blocks) - 1):        
        if blocks[i] == frc:
            res.append(i + 1)
            blocks[i] = toc
            if blocks[i+1] == frc:
                blocks[i + 1] = toc
            else:
                blocks[i + 1] = frc
    print(len(res))
    print(*res)
n = int(input()) 
blocks = input()

wc = 0
bc = 0

for b in blocks:
    if b=='W':
        wc+=1
    else:
        bc+=1

if wc % 2 != 0 and bc % 2 != 0:
    print(-1)
elif wc % 2 == 0 and bc % 2 != 0:
    turn(list(blocks), 'W', 'B')
elif wc % 2 != 0 and bc % 2 == 0:
    turn(list(blocks),'B', 'W')
else:
    if wc <= bc:
        if wc > 0:
            turn(list(blocks),'W', 'B')
        else:
            print(0)
    else:
        if bc > 0:
            turn(list(blocks),'B', 'W')
        else:
            print(0)

