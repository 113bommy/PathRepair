while True :
    x=int(input(""))
    if (0<x<31):
        break
l=list()
for i in range(x):
    while True :
        s=0
        y=input("")
        if (y[0]!='_' and y[-1]!='_' and 0<len(y)<1001 and y.islower()):
            s+=1
        for i in range(1,len(y)-1):
            if(y[i]+y[i+1]=='__'):
                s-=1
        for i in range (1,len(y)-1):
            if(ord(y[i])<ord("a") and ord(y[i])>ord("z") and ord(y[i])!=ord('_')):
                s-=1
        if(s==1):
            break
    l.append(y)    
for i in range(x):
    if (l[i][len(l[i])-5:]=="mnida"):
        print("KOREAN")
    elif (l[i][len(l[i])-4:] in ["desu","masu"]):
        print("JAPANESE")
    else :
        print("FILIPINO")
