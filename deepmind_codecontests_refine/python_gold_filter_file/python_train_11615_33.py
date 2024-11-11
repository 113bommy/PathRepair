
import sys

formato = int(input());
numeros = list(map(int,input().split(":")));

min=0
nMin=2
if formato==12:
    for i in range(1,13):
        minAux=0
        if(numeros[0]%10!=i%10):
            minAux+=1
        if(numeros[0]/10!=i/10):
            minAux+=1
        if minAux<=nMin:
            nMin = minAux
            min = i
else:
     for i in range(0,24):
        minAux=0
        if(numeros[0]%10!=i%10):
            minAux+=1
        if(numeros[0]/10!=i/10):
            minAux+=1
        if minAux<=nMin:
            nMin = minAux
            min = i

nMin=2
minMin=0
for i in range(0,60):
        minAux=0
        if(numeros[1]%10!=i%10):
            minAux+=1
        if(numeros[1]/10!=i/10):
            minAux+=1
        if minAux<=nMin:
            nMin = minAux
            minMin=i

print(str(min).zfill(2) +":"+str(minMin).zfill(2) )
