ax = input()
bx = input()
res=[]
if(ax==bx):
    print(0)
    print("")
    exit(0)
ay = int(ax[1:])
ax=ax[:1]
by=int(bx[1:])
bx=bx[:1]
dx=ord(bx)-ord(ax)
dy=by-ay
if(dx<=0 and dy<=0):
    for i in range(min(abs(dx),abs(dy))):
        res.append("LD")
    if(abs(dx)<abs(dy)):
        for i in range(abs(dy)-abs(dx)):
            res.append("D")
    if(abs(dy)<abs(dx)):
        for i in range(abs(dx)-abs(dy)):
            res.append("L")
elif(dx>=0 and dy<=0):
    for i in range(min(abs(dx),abs(dy))):
        res.append("RD")
    if(abs(dx)<abs(dy)):
        for i in range(abs(dy)-abs(dx)):
            res.append("D")
    if(abs(dy)<abs(dx)):
        for i in range(abs(dx)-abs(dy)):
            res.append("R")
elif(dx<=0 and dy>=0):
    for i in range(min(abs(dx),abs(dy))):
        res.append("LU")
    if(abs(dx)<abs(dy)):
        for i in range(abs(dy)-abs(dx)):
            res.append("U")
    if(abs(dy)<abs(dx)):
        for i in range(abs(dx)-abs(dy)):
            res.append("L")
else:
    for i in range(min(abs(dx),abs(dy))):
        res.append("RU")
    if(abs(dx)<abs(dy)):
        for i in range(abs(dy)-abs(dx)):
            res.append("U")
    if(abs(dy)<abs(dx)):
        for i in range(abs(dx)-abs(dy)):
            res.append("R")
print(max(abs(dx),abs(dy)))
for i in res:
    print(i)