t = int(input())
for i in range(t):
    a, b = input().split()
    a = int(a) #modifica a
    b = int(b) #aggiungi dispari o sottrai pari
    x = 0
    while a != b:
        if a < b:
            if (b-a)%2 == 0:
                a += b-a-1
                a += 1
                x += 2
            elif (b-a)%2 == 1:
                a += b-a
                x += 1
        elif a == b:
            print("0")
        elif a > b:
            if (a-b)%2 == 0:
                a -= a-b
                x += 1
            elif (a-b)%2 == 1:
                a -= a-b+2
                a += 1
                x += 1
    print(x)
