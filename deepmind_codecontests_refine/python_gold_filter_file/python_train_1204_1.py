
n=int(input()) ## input the number of pokemons

entree=list(map(int,input().split())) ## get entries 

compter = 1 ## get the maximum pokemon , but we're sure that at leaset we've one pokemon so i put it at 1

t=[0 for i in range(10**5+1)] ## a custom array fill will 0

for i in entree:

    t[i]+=1## i fill it with one , since at the beginning , all of them has the chance to fight against others

for i in range(2,10**5+1):##start from two because i set all of them at one , so the first will start from the second and go till end, the second will start from the third till the end etc... 
    
    compteur=0
   
    for j in range(i,10**5+1,i):## the last i in the bracket show the steps a pokemon does for instance the first will go one steps by step....The second will go two steps by two steps

        compteur = compteur + t[j]

    compter = max(compter,compteur)

print(compter)
