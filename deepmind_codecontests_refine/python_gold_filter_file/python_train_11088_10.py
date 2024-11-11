import sys

def solve(n, x):
        
    ant = x[0]
    cont = 1
    maximo = 1
    maxi = 1
    dos = 0
    for i in range(1, n):
        if(ant != x[i]):
            cont += 1
            ant = x[i]
            if(maximo >= 2):    
                dos += 1
            maximo = 1
        else:
            maximo += 1
        maxi = max(maxi, maximo)
    if(maximo >= 2):
        dos += 1
#    print(maxi, cont)
    if(maxi >= 3 or dos >= 2):
        return cont + 2
    if(dos == 1):
        return cont+1
    return cont

n = int(input())
x = input()
print(solve(n, x))