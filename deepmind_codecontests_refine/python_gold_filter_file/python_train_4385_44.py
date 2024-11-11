[x,y,z,t1,t2,t3] = map(int, input() .split())
floors = abs(x-y)
floortime = floors*t1 
elevatorwait = abs(z-x)*t2 +2*t3
elevatortime = elevatorwait+floors*t2+t3  
#print(floors,floortime,elevatortime,elevatorwait)
if floortime>=elevatortime:
    print('YES')
else:
    print('NO')
