sa=input().split(' ')
boys=int(sa[0])
girls=int(sa[1])
dlist=[]
if boys==girls:
    for x in range(1, boys):
        dlist.append([x, x])
        dlist.append([x, x+1])
    dlist.append([boys, boys])
    print(len(dlist))
    for element in dlist:
        print(str(element[0])+' '+str(element[1]))
elif boys<girls:
    for x in range(1, boys):
        dlist.append([x, x])
        dlist.append([x, x+1])
    for y in range(boys, girls+1):
        dlist.append([boys, y])
    print(len(dlist))
    for element in dlist:
        print(str(element[0])+' '+str(element[1]))
else:
    boys, girls=girls, boys
    for x in range(1, boys):
        dlist.append([x, x])
        dlist.append([x, x+1])
    for y in range(boys, girls+1):
        dlist.append([boys, y])
    print(len(dlist))
    for element in dlist:
        print(str(element[1])+' '+str(element[0]))
