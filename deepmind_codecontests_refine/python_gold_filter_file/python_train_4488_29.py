n,k = map(int,input().split())
mot = input()

alphabet= "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

s= alphabet[:k]
l=[]
for elem in s:
    occ= mot.count(elem)
    l.append(occ)
l.sort()
print(l[0]*k)