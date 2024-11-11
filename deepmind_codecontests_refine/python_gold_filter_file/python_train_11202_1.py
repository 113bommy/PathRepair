# -*- coding: utf-8 -*-

m=input()
l= input()

texte = input()
langue = []
modifie = []
dechif = ''

for i in range(len(l)):
    langue.append(str(l[i]))
    modifie.append(str(m[i]))
L = ['0','1','2','3','4','5','6','7','8','9']
for k in L:
    langue.append(k)
    modifie.append(k)
for j in texte:
    if j.isupper():
        dechif += str(langue[modifie.index(str(j.lower()))]).upper()
    else:
        dechif += str(langue[modifie.index(str(j))])
print(dechif)
    
