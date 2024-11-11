q = int(input())
numer = 0
import random
def ope(numer, tablica):
    if numer == 0:
        tablica[0] = min(tablica[0], tablica[1]+tablica[5])
    if numer == 1:
        tablica[1] = min(tablica[1], tablica[0]+tablica[2])
    if numer == 2:
        tablica[2] = min(tablica[2], tablica[1] + tablica[3])
    if numer == 3:
        tablica[3] = min(tablica[3], tablica[2]+tablica[4])
    if numer == 4:
        tablica[4] = min(tablica[4], tablica[3]+tablica[5])
    if numer == 5:
        tablica[5] = min(tablica[5], tablica[4]+tablica[0])
for _ in range(q):
    x,y = map(int,input().split())
    c = list(map(int,input().split()))
    for i in range(6):
        ope(numer,c)
    for i in range(600):
        a = random.randint(0,5)
        ope(a,c)
    if x >= 0:
        dod = 0
        if y >= x:
            wyn = c[0+dod]*x+c[1+dod]*(y-x)
        else:
            if y >= 0:
                wyn = (x-y) * c[5+dod] + y * c[dod]
            else:
                wyn = x * c[5+dod] - y * c[4+dod]
    else:
        x *= (-1)
        y *= (-1)
        dod = 3
        if y >= x:
            wyn = c[0-dod]*x+c[1-dod]*(y-x)
        else:
            if y >= 0:
                wyn = (x-y) * c[5-dod] + y * c[-dod]
            else:
                wyn = x * c[5-dod] - y * c[4-dod]
    print(wyn)