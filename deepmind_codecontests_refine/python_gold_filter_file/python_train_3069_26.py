w=0
b=0
x=input()
for i in range(7):
    x+=input()
lnx=len(x)
for i in range(lnx):
    if x[i]=='Q':
        w+=9
    elif x[i]=='R':
        w+=5
    elif x[i]=='B':
        w+=3
    elif x[i]=='N':
        w+=3
    elif x[i]=='P':
        w+=1
    elif x[i]=='q':
        b+=9
    elif x[i]=='r':
        b+=5
    elif x[i]=='b':
        b+=3
    elif x[i]=='n':
        b+=3
    elif x[i]=='p':
        b+=1
if w>b:
    print('White')
elif w<b:
    print('Black')
else:
    print('Draw')