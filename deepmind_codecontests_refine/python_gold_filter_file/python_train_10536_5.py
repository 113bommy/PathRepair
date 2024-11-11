q=int(input())
for i in range(q):
    cu=0
    cd=0
    cl=0
    cr=0
    mayc=0
    maya=0
    cad=str(input())
    for l in cad:
        if (l=="U"):
            cu+=1
        elif (l=="D"):
            cd+=1
        elif (l=="L"):
            cl+=1
        elif (l=="R"):
            cr+=1
    if (cu <= cd):
        mayc=cu
    else:
        mayc=cd
    if (cl <= cr):
        maya=cl
    else:
        maya=cr
    s=(2*mayc)+(2*maya)
    if (mayc > 0 and maya > 0):
        print(s)
        print(("U"*mayc)+("L"*maya)+("D"*mayc)+("R"*maya))
    elif (mayc > 0):
        print(2)
        print("UD")
    elif (maya > 0):
        print(2)
        print("RL")
    else:
        print(0)
        print()
    
