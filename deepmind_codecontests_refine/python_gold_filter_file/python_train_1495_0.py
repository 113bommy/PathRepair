def count(l,L):
    x=0
    if L<=9:x=L
    else:
        x+=9
        if L<=100:x+=(L//11)
        else:
            x+=9
            leng=len(l)
            for i in range(max(0,leng-3)):
                x+=(9*(10**(i+1)))
            leng-=2
            for i,y in enumerate(l[:-1]):
                y=int(y)
                if i==0:y-=1
                if y>0:x+=(y*(10**leng))
                leng-=1
            if int(l[-1])>=int(l[0]):x+=1
    return x
l1,l2=map(str,input().split())
a=count(l1,int(l1))
b=count(l2,int(l2))
if int(l1[0])==int(l1[-1]):a-=1
print(b-a)