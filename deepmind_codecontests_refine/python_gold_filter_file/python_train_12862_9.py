n=int(input())
bus=[]
for i in range(0,n):
    bus.append(input())
answer='NO'
i=0
while (answer=='NO')and(n-1>=i):
    if bus[i][0]+bus[i][1]=='OO':
        answer='YES'
        bus[i]='++|'+bus[i][3]+bus[i][4]
    elif bus[i][3]+bus[i][4]=='OO':
        answer='YES'
        bus[i]=bus[i][0]+bus[i][1]+'|++'
    i+=1
print(answer)
if answer=='YES':
    for i in range(0,n):
        print(bus[i])
