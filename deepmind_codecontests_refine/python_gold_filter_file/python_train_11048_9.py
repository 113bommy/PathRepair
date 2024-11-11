import sys

for s in sys.stdin:
    totx = 0
    toty = 0
    for i in range(0,int(s)*2):
        x,y = input().split(" ")
        x = int(x)
        y = int(y)
        totx += x
        toty += y
    totx= totx/int(s)
    toty= toty/int(s)
    print("%.0f %.0f"%(totx,toty))
