t = int(input())

for k in range(t):
    donnees = input().split(" ")
    n = int(donnees[0])
    a = int(donnees[1])
    b = int(donnees[2])
    q = n // a
    r = n % a
    for l in range(q):
        compt = 0
        for j in range(a-b+1):
            print(chr(97), end = "")
        for z in range(b-1):
            compt += 1
            print(chr(97+compt), end = "")
    compteur = 0
    while compteur <= a-b and compteur <= r-1:
        print(chr(97), end = "")
        compteur += 1
    compt2 = 1
    while compteur <= r-1:
        print(chr(97+compt2), end = "")
        compt2 += 1
        compteur += 1
    print()