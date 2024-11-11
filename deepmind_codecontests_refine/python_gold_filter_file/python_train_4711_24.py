from sys import stdin as lector
input = lector.readlines()
n=int(input[0])
for i in range(2,2*n+1,2):
    lista=input[i].split(" ")
    numeros=list(map(lambda x : int(x), lista))
    orden=sorted(numeros)
    min=abs(orden[1]-orden[0])
    for j in range(len(orden)-1,0,-1):
        if orden[j]-orden[j-1]<min:
            min=orden[j]-orden[j-1]
    print(min)
        