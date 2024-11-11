import random as r #>= 1 Y
s=int(input())
mi=-2000000000
ma=2000000000
for i in range(s):
    x,y,z=map(str,input().split())
    if z=='Y':
        if len(x)==1:
            if x[0]=="<":
                ma=min(ma,(int(y)-1))
            else:
                mi=max(mi,(int(y)+1))
        else:
            if x[0]=="<":
                ma=min(ma,int(y))
            else:
                mi=max(mi,int(y))
    if z=='N':
        if len(x)==1:
            if x[0]==">":
                ma=min(ma,(int(y)))
            else:
                mi=max(mi,(int(y)))
        else:
            if x[0]==">":
                ma=min(ma,(int(y)-1))
            else:
                mi=max(mi,(int(y)+1))
if mi>ma:
    print("Impossible")
else:
    print(mi)
                
    


    
