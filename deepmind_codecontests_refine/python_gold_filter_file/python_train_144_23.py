#coding: utf-8

n, c = input().split()
n, c = int(n), int(c)

lista = list(map(int, input().split()))

rasp = 0
inferno = []
guloso = 0

for x in range(len(lista)-1):
    if (lista[x] - c) - lista[x + 1] >= guloso:
        guloso = (lista[x] -c) - lista[x + 1]
        
print(guloso)