ftot = int(input())
nlun = list("x") * ftot
pare = list("x") * ftot
y, cont, c, d = 0, 0, 0, 0
a, b = '(', ')'
for x in range(ftot):
    nlun[x] = int(input())
    pare[x] = input()
for x in range(ftot):
    pare[x] = list(pare[x])
while cont < ftot:
    y=0
    while y < 26 and 0 < len(pare[cont]):
        y += 1
        d = 0
        x = 0
        while 0 < (len(pare[cont]) - 1):
            d += 1
            if (len(pare[cont]) - 1) > x and pare[cont][x] == a and pare[cont][x + 1] == b:
              #  print(pare[cont])
                pare[cont].pop(x)
                pare[cont].pop(x)
               # print(pare[cont])
            if (len(pare[cont]) - 1) > x:
                x += 1
            if d > 49:
                break
    print(len(pare[cont]) // 2)
    cont += 1
