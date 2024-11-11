import math
t = int(input())
# ss = input()
for _ in range(t):
    n = int(input())
    # ss = input()
    x1 = -1e9
    x2 = 1e9
    x3 = 1
    x4 = -1e9
    x5 = 1e9
    x6 = 1
    for i in range(n):
        l = [int(x) for x in input().split()]
        # ss = input()
        l[3], l[4] = l[4], l[3]
        if(l[2] == 0 and l[3] == 0):
            if(l[0] >=x1 and l[0]<=x2):
                x1 = l[0]
                x2 = l[0]
            else:
                x3 = 0
        elif(l[2] == 0 and l[3] == 1):
            if(l[0]>x2):
                x3 = 0
            else:
                if(l[0]>=x1):
                    x1 = l[0]

            # print("jai", x1, x2)  
                    
        elif(l[2] == 1 and l[3] == 0):
            if(l[0]<x1):
                x3 = 0
            else:
                if(l[0]<=x2):
                    x2 = l[0]

        
        if(l[4] == 0 and l[5] == 0):
            if(l[1] >=x4 and l[1]<=x5):
                x4 = l[1]
                x5 = l[1]
            else:
                # print("bam bam bole", l[1])
                x6 = 0
        elif(l[4] == 0 and l[5] == 1):

            if(l[1]<x4):
                x6 = 0
            else:
                if(l[1]<=x5):
                    x5 = l[1]
                    
        elif(l[4] == 1 and l[5] == 0):
            if(l[1]>x5):
                x6 = 0
            else:
                if(l[1] >= x4):
                    x4 = l[1]


    # print(x1, x2, x4, x5, x3, x6)
    if(x3 == 0 or x6 == 0):
        print(0)
    else:
        X = 0
        Y = 0
        if(x1 == -1e9):
            if(x2 == 1e9):
                X = 0
            else:
                X = x2
        else:
            X = x1
        if(x4 == -1e9):
            if(x5 == 1e9):
                Y = 0
            else:
                Y = x5
        else:
            Y  =x4
        

        print(1, X, Y)




