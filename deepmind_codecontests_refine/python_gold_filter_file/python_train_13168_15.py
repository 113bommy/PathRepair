n,s = input().split()
n,s = int(n),int(s)
dic = {}
while n > 0:
    listOfInput = input().split()
    key = ' '.join(listOfInput[:-1])
    value = listOfInput[-1]
    if key in dic:
        dic[key]+=int(value)
    else:
        dic[key] = int(value)
    n-=1
listOfSells = sorted([int(key.split()[1]) for key in dic if key.split()[0] == 'S'])[:s]
listOfBuys = sorted([int(key.split()[1]) for key in dic if key.split()[0] == 'B'])
for i in range(s):
    if listOfSells:
        value = listOfSells.pop()
        key = 'S '+str(value)
        print('S '+str(value)+' '+str(dic[key]))
    else:
        pass
for i in range(s):
    if listOfBuys:
        value = listOfBuys.pop()
        key = 'B '+str(value)
        print('B '+str(value)+' '+str(dic[key]))
    else:
        pass
    
