way=list(input())
if len(way)%2==1:
    print (-1)
else:
    rast=0
    bala=0
    for i in way :
        if i =="R":rast-=1
        elif i =='L':rast+=1
        elif i =='D':bala+=1
        else :bala-=1
    if rast<0:rast=-rast
    if bala <0:bala=-bala
    t=rast//2 + bala//2 +rast%2
    print (t)