
for _ in range(int(input())):
    initialinput = int(input())
    counter = 0
    cbn = 1
    sqrn = 2
    while cbn ** 3 <= initialinput:
        counter += 1
        cbn += 1
    while sqrn ** 2 <= initialinput:
        counter += 1
        sqrn += 1

    sqrn = 1
    while sqrn ** 6 <= initialinput:
        counter -= 1
        sqrn += 1

    print(counter+1)







