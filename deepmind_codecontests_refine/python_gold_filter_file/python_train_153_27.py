B=0
D={}
while 1:
    try:
        r=input()
        if r[0]=='+':
            D[r[1:]]=1
        elif r[0]=='-':
            D[r[1:]]=0
        else:
            o=r.find(':')
            B+=len(r[o+1:])*sum(D.values())
    except EOFError:
        print(B)
        break