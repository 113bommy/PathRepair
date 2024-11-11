f1,t1 = [int(x) for x in input().split()]
f2,t2 = [int(x) for x in input().split()]

minutosTotales = 23*60+59-5*60

buses = []
for hora in range(0,minutosTotales+1,f2):
    buses.append((hora,hora+t2))

horaInicio = input().split(":")
horaInicio = (int(horaInicio[0])-5)*60+int(horaInicio[1])

c=0
for bus in buses:
    if not(bus[1]<=horaInicio or horaInicio+t1<=bus[0]):
        c+=1
print(c)
