from math import *
n=int(input())
lista=[int(i) for i in input().split()]
lista.sort(reverse=True)
area=0
tam=len(lista)
for r in lista:
    area+=(-1)**(tam-1)*pi*r*r
    tam-=1
print(abs(area))