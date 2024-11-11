var1, var2=input().split()
listname=[]
listcommand=[]
listsorite=[]
for i in range(int(var1)):
    nameip=input() 
    listname.append(nameip)
for j in range(int(var2)):
    commandip=input() 
    listcommand.append(commandip)
    listcommandsplit=commandip.split(" ")
    listcommandsplit11=listcommandsplit[1].split(";")
    for i in range(int(var1)):
        listnamesplit=listname[i].split(" ")
        if(listcommandsplit11[0]==listnamesplit[1]):
            listsorite.append(commandip +" #"+listnamesplit[0])

for i in range(len(listsorite)):
    print(listsorite[i])