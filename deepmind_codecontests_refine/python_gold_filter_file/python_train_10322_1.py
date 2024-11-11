def answer():
    a = int(input())
    b = [int(x) for x in input().split()]
    i=0
    b.reverse()
    thingo=b[0]
    if thingo==0:targ=1
    else: targ =0
    print(len(b)-b.index(targ))
answer()
