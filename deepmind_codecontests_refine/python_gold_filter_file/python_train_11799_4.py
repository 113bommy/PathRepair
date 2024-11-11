n,t = map(int, input().split())
lista_punktow = list()
lista_odleglosci = list()
suma= 0

for i in range(n):
    x,a  = map(int, input().split())
    lista_punktow.append(float(x-a/2))
    lista_punktow.append(float(x+a/2))

lista_punktow.sort()
#print (lista_punktow)

for i in range(0,len(lista_punktow)-2,2):
    w = lista_punktow[i+2] - lista_punktow[i+1]
    lista_odleglosci.append(w)

#print(lista_odleglosci)

for i in range(len(lista_odleglosci)):
    if (lista_odleglosci[i] - t) > 0:
        d = (lista_odleglosci[i] - t)
        suma += 2
    elif (lista_odleglosci[i] - t) == 0:
        suma +=1
print (suma+2)