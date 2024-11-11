while True:
    [H,W]=[int(x) for x in input().split()]
    if [H,W]==[0,0]:
        break
    unit="#."
    for i in range(0,H):
        print(unit*(W//2)+unit[0]*(W%2))
        unit=unit[1]+unit[0]
    print("")