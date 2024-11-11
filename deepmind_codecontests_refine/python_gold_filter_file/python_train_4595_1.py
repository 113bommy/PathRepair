w,h=map(int,input().split())
s1,h1=map(int,input().split())
s2,h2=map(int,input().split())
while h!=0:
    if h==h1:
        w+=h
        h-=1
        w-=s1
        if w<0:w=0
    elif h==h2:
        w+=h
        h-=1
        w-=s2
        if w<0:w=0
    else:
        w+=h
        h-=1
if w>0:print(w)
else:print("0")