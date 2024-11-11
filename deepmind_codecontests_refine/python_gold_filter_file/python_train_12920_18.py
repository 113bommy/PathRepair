n = int(input())

for i in range(n):
    s = input()
    bm = 0
    bb = 0
    c = 0

    for j in s:
        if ord(j)>=65 and ord(j)<=90:
            bb +=1
        elif ord(j)>=97 and ord(j)<=122:
            bm +=1
        elif ord(j)>=48 and ord(j)<=57:
            c +=1
    for j in s:
        if not bb:
            if (bm>1) and (ord(j)>=97 and ord(j)<=122):
                print('A', end='')
                bb = 1
                bm-=1
                continue
            if (c>1) and (ord(j)>=48 and ord(j)<=57):
                print('A', end='')
                bb = 1
                c-=1
                continue

        if not bm:
            if (bb>1) and (ord(j)>=65 and ord(j)<=90):
                print('a', end='')
                bm = 1
                bb-=1
                continue
            if (c>1) and (ord(j)>=48 and ord(j)<=57):
                print('a', end='')
                bm = 1
                c-=1
                continue

        if not c:
            if (bb>1) and (ord(j)>=65 and ord(j)<=90):
                print('0', end='')
                c = 1
                bb-=1
                continue
            if (bm>1) and (ord(j)>=97 and ord(j)<=122):
                print('0', end='')
                c = 1
                bm-=1
                continue
        print(j, end='')
    print()


