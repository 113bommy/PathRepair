def minst(l1,l2):
    if l1<l2:
        return l1
    elif l2<l1:
        return l2
    else:
        return(0)
t=int(input())
l=[]
for i in range(t):
    ch=input()
    liste=ch.split()
    l1=int(liste[0])
    l2=int(liste[1])
    l3=int(liste[2])
    l.append([l1,l2,l3])
for i in l:
    l1=i[0]
    l2=i[1]
    l3=i[2]
    if l1==l2 :
        if l3%2 == 0:
            print('Yes')
        else:
            print('NO')
    elif l1==l3:
        if l2%2 == 0:
            print('Yes')
        else:
            print('NO')
    elif l2==l3:
        if l1%2 == 0:
            print('Yes')
        else:
            print('NO')
    else:
        l4=max(l1,l2,l3)
        l5=min(l1,l2,l3)
        l6=max(minst(l4,l1),minst(l4,l2), minst(l4,l3))
        
        if l4==(l5+l6):
            print('Yes')
        else:
            print('NO')
    
