numTests = int(input())
for _ in range(numTests):
    numCols = int(input())
    cols = [int(i) for i in input().split()]
    col1 = cols[0] % 2
    good = True
    for ii in range(1,numCols):
        if (cols[ii]%2) != col1:
            print("NO")
            good = False
            break
    if good:
        print("YES")