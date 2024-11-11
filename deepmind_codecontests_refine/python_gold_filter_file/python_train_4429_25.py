n,c=map(int,input().split(" "))
p=list(map(int,input().split(" ")))
t=list(map(int,input().split(" ")))
timel,timer,pointl,pointr=0,0,0,0
ln=len(p)
for i in range(ln):
    timel=timel+t[i]
    timer=timer+t[ln-1-i]
    pointl=pointl + (p[i]-c*timel if(p[i]-c*timel>0) else 0)
    pointr=pointr + (p[ln-1-i]-c*timer if(p[ln-1-i]-c*timer>0) else 0)
    #print(timel,timer,pointl,pointr)
if(pointl==pointr):
    print('Tie')
else:
    if(pointl>pointr):
        print("Limak")
    else:
        print("Radewoosh")
