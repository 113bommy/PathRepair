nab=list(map(int,input().strip().split()))
n=nab[0]
a=nab[1]
b=nab[2]
chores=list(map(int,input().strip().split()))
chores.sort(reverse=True)
d=a
while(d>0):
    prev=chores[0]
    chores.pop(0)
    d=d-1
#print(chores)
for i in chores:
    if(prev==i):
        print('0')
        break
    else:
        c=len(chores)
        print(prev-chores[0])
        break




