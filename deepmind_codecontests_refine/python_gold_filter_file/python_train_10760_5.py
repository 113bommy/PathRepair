# recebe e converte a primeira linha
n = input()
n,k = n.split()
n = int(n)
k = int(k)

# recebe e converte a segunda linha
i = input()
numeros=[]
numeros=i.split()
for i in range(k):
     numeros[i] = int(numeros[i])

laranja=[-1 for i in range(n*k+1)]

# setar os numeros que os meninos pediram para dentro da lista laranja
for i in range(k):
    laranja[numeros[i]]=i


count=n-1
for i in range(k):  #para cada criança
    for j in range(1,n*k+1):
        if laranja[j]== -1:
            laranja[j]=i
            count-=1
        if count==0:
            count=n-1
            break

for j in range(k):
    for i in range(1,n*k+1):
        if laranja[i]==j:
            print(i, " ", end="")
    print()