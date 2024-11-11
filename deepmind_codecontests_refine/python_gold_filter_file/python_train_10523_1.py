while True:
    m,f,r= map(int,input().split())
    if m+f+r==-3:break
    if m==-1 or f==-1:s="F"
    elif m+f>=80:s="A"
    elif m+f>=65:s="B"
    elif m+f>=50:s="C"
    elif m+f>=30 and r>=50:s="C"
    elif m+f>=30:s="D"
    else:s="F"
    print(str(s))
