n = int(input())
b = input()

dico = {}

for i in range(n-1):
    if b[i] + b[i+1] in dico:
        dico[ b[i] + b[i+1] ] += 1

    else:
        dico[ b[i] + b[i+1] ] = 0

maxi = 0
chaine = ""
for i in dico:
    if dico[i] >= maxi:
        maxi = dico[i]
        chaine = i
print(chaine)
