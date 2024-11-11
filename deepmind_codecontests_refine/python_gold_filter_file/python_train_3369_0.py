n = int( input() )

a = []
MAXN = 100

for i in range(MAXN):
    a.append( [0]*MAXN )

for i in range(3):
    for j in range(3):
        if i != j:
            a[i][j] = 1

cycles = 1

if cycles != n:
    for i in range(3,MAXN):

        if cycles == n:
            break

        a[i][0] = a[0][i] = 1
        a[i][1] = a[1][i] = 1

        cycles += 1

        if cycles == n:
            break

        how = 2

        for j in range(2,i):
            if a[i][j] == 1:
                continue
            if j != i:
                if cycles + how <= n:
                    a[i][j] = a[j][i] = 1
                    cycles += how
                    how += 1
                    if cycles == n:
                        break

print(MAXN)

for i in range( len(a) ):
    for j in a[i]:
        print( j, end='')
    print()
