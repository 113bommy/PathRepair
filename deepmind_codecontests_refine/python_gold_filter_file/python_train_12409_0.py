def digg(dic, num):

    if d[num%10] == 1:

        for i in d:
            d[i] = 0

        return False
    elif num%10 == num:
        for i in d:
            d[i] = 0

        return True
    else:
        d[num%10] = 1
        return digg(d, num//10)

d = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0}

a, b = map(int, input().split())

for i in range(a, b+1):

    aux = i%10
    d[aux] = 1
    aux = digg(d, i//10)

    if aux == True:
        print(i)
        break

if aux == False:
    print(-1)

