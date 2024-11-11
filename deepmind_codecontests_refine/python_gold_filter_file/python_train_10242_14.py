l = [[0 for i in range(5)] for j in range(5)]

for i in range(1,4):
    l[i][1:4]=[int(j) for j in input().split()]

for i in range(1,4):
    for j in range(1,4):
        s = l[i][j]+l[i+1][j]+l[i][j+1] +l[i-1][j]+l[i][j-1]
        if s%2==0:
            print("1",end="")
        else:
            print("0",end="")
    print()