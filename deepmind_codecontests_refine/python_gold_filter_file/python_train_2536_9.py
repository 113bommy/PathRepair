n=input()
x=''
if n[0]=='h':
    x+='http://'
    z=n.index('ru')
    if z!=4:
        x+=n[4:z]
        x+='.ru/'
        x+=n[z+2:]
    else:
        h=n[6:].index('ru')+6
        for i in range(4,h):
            x+=n[i]
        x+='.ru'
        x+='/'+n[h+2:]
else:
    x+='ftp://'
    z=n.index('ru')
    if z!=3:
        x+=n[3:z]
        x+='.ru/'
        x+=n[z+2:]
    else:
        h=n[6:].index('ru')+6
        for i in range(3,h):
            x+=n[i]
        x+='.ru'
        x+='/'+n[h+2:]
if x[-1]=='/':
    x=x[:-1]
print(x)
