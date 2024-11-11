#parsea una línea
def parser():
    return [int(x) for x in input().split()]
    
#Recibiendo n y m
n,m=parser()
#Recibiendo los colores de los vértices
colors_vertices=parser()
colors=set(colors_vertices)

#Creando los sets
adjacents_sets=[set() for x in colors]

#Creando el diccionario
color_pos={}

#Llenano el diccionario con los colores y las posiciones
i=0
for color in colors:
    color_pos[color]=i
    i+=1

#Se llenan los conjuntos usando el diccionario
for i in range(m):
    #Leyendo una arista
    edge=parser()
    #Obteniendo los colores de los vértices
    color1=colors_vertices[edge[0]-1]
    color2=colors_vertices[edge[1]-1]
    #Si son diferentes añadimos cada color al conjunto de adyacentes del otro color
    if color1!=color2:
        adjacents_sets[color_pos[color1]].add(color2)
        adjacents_sets[color_pos[color2]].add(color1)

#Cantidad máxima de colores vecinos
max_neighbours=-1
#Menor color que tiene dicha cantidad
result=-1

#Hallando dicha cantidad y dicho color
for color in color_pos:
    if max_neighbours<len(adjacents_sets[color_pos[color]]):
        max_neighbours=len(adjacents_sets[color_pos[color]])
        result=color
    if max_neighbours==len(adjacents_sets[color_pos[color]]) and color<result:
        result=color

#Imprimimiendo el color hallado
print(result)