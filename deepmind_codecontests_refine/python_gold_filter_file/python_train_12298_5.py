# -*- coding: utf-8 -*-

lista,power = [],0
n,p1,p2,p3,t1,t2 = map(int,input().split())

for i in range(n):
    work = list(map(int,input().split()))
    lista.append(work); power += (work[1]-work[0])*p1
    if len(lista) > 1:
        descanso = lista[i][0]-lista[i-1][1]
        if descanso <= t1: power += p1*descanso
        elif descanso <= t1+t2: power += p1*t1 + p2*(descanso-t1)
        else: power += p1*t1 + p2*t2 + (descanso-t1-t2)*p3
        
print(power)

