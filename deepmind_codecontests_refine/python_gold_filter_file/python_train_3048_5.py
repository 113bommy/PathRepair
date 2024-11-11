powersof2=[]
for i in range(31):
    powersof2.append(2**i)

t=int(input())
for x in range(t):
    c=input().split()
    a=int(c[0])
    b=int(c[1])
    abinary=[]
    bbinary=[]
    for i in range(31):
        if powersof2[i]>a:
            apower=i-1
            break
    for i in range(31):
        if powersof2[i]>b:
            bpower=i-1
            break
    for i in range(apower,-1,-1):
        if a-powersof2[i]>=0:
            abinary.append(1)
            a-=powersof2[i]
        else:
            abinary.append(0)

    for i in range(bpower,-1,-1):
        if b-powersof2[i]>=0:
            bbinary.append(1)
            b-=powersof2[i]
        else:
            bbinary.append(0)
            
    if abinary==bbinary:
        d=0
        
    elif abinary!=bbinary:
        if len(abinary)<len(bbinary):
            c=len(bbinary)-len(abinary)
            for i in range(c):
                abinary.insert(0, 0)
        elif len(bbinary)<len(abinary):
            c=len(abinary)-len(bbinary)
            for i in range(c):
                bbinary.insert(0, 0)
        for i in range(len(bbinary)):
            if bbinary[i]==abinary[i] and bbinary[i]==1:
                bbinary[i]=0
                abinary[i]=0
        
        b=0
        a=0
        for i in range(len(bbinary)):
            if bbinary[i]==1:
                c=len(bbinary)-i-1
                b+=2**c
            elif abinary[i]==1:
                c=len(abinary)-i-1
                a+=2**c
        d=a+b
    print(d)
    
        
        
            


