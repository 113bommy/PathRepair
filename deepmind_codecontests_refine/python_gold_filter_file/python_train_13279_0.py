shirts_count=list(map(int,input().split()))
no=False
n=0
for i in shirts_count:
   n+=i 
sizes=('S','M','L','XL','XXL','XXXL')
shirts=dict()
children=list()
for i in range(len(sizes)):
    shirts[sizes[i]]=shirts_count[i]
for i in range(int(input())):
    children.append(input().split(','))
if n<len(children):
    print('NO')
else:
    itog=[0]*len(children)
    for i in range(len(children)):
        if len(children[i])==1:
            if shirts[str(children[i][0])]>0:
                shirts[str(children[i][0])]-=1
                itog[i]=str(children[i][0])
            else:
                no=True
    a=0
    while a<5 and not no:
        for i in range(len(children)):
            if len(children[i])>1:
                if sizes[a]==children[i][0] and sizes[a+1]==children[i][1]:
                    if shirts[sizes[a]]>0:
                        itog[i]=sizes[a]
                        shirts[sizes[a]]-=1
                    else:
                        if shirts[sizes[a+1]]>0:
                            itog[i]=sizes[a+1]
                            shirts[sizes[a+1]]-=1
                        else:
                            no=True
        a+=1
    if not no:
        print('YES')
        for i in range(len(itog)):
            print(itog[i])
    if no:
        print('NO')
