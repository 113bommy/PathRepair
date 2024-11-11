ma=[]
mi=[]
def max_find_digit(nod,sum):
    global ma
    if(nod>1):
        t=sum-(nod-1)*9
        if(t>9 or sum==0):
            return
        if(t<0):
            t=0
        ma.append(t)
        if(sum-t>=0):
            max_find_digit(nod-1,sum-t)
        return
    else:
        if(sum>=0 and sum<10):
            ma.append(sum)
        return

def min_find_digit(nod,sum):
    global mi
    if(nod>1):
        t=sum-(nod-1)*9
        if(t>9 or sum==0):
            return
        if(t<1):
            t=1
        mi.append(t)
        def max_find_digit(nod,sum):
            if(nod>1):
                t=sum-(nod-1)*9
                if(t<0):
                    t=0
                mi.append(t)
                if(sum-t>=0):
                    max_find_digit(nod-1,sum-t)
                return
            else:
                if(sum>=0 and sum<10):
                    mi.append(sum)
                return
        max_find_digit(nod-1,sum-t)
        return
    else:
        if(sum>=0 and sum<10):
            mi.append(sum)
        return


    
x=[]
x=input().split()
x[0]=int(x[0])
x[1]=int(x[1])
max_find_digit(x[0],x[1])
min_find_digit(x[0],x[1])

ma=ma[::-1]
m=[]
if(len(mi)<x[0]):
    m.append(-1)
else:
    min=''
    for i in range(x[0]):
        min=min+str(mi[i])
    m.append(int(min))

if(len(ma)<x[0]):
    m.append(-1)
else:
    max=''
    for i in range(x[0]):
        max=max+str(ma[i])
    m.append(int(max))

print(m[0],m[1])
