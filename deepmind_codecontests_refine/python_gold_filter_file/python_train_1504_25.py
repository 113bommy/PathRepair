l,h=-2000000000,2000000000
for _ in range(int(input())):
    x,y,z=[_ for _ in input().split()]
    y=int(y)
    if x=="<=":
        if z=="Y":
            if h>y:h=y
        else:
            if l<y:l=y+1
    if x=="<":
        if z=="Y":
            if h>y-1:h=y-1
        else:
            if l<y:l=y
    if x==">=":
        if z=="Y":
            if l<y:l=y
        else:
            if h>y-1:h=y-1
    if x==">":
        if z=="Y":
            if l<y+1:l=y+1
        else:
            if h>y:h=y
if l>h: print("Impossible")
else:print(l)
'''if -1000000000<=l<=h<=1000000000:print(l)
elif -1000000000<=h<l<=1000000000:print("Impossible")
else:print(2000000000 if l>h else-2000000000)'''