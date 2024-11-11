while True:
    m,f,r=map(int,input().split())
    if m==f==r==-1:break
    a=m+f
    if m==-1 or f==-1:print('F')
    elif a >= 80:print('A')
    elif a >= 65:print('B')
    elif a >= 50:print('C')
    elif a >= 30:
        if r >= 50:print('C')
        else:print('D')
    else:print('F')