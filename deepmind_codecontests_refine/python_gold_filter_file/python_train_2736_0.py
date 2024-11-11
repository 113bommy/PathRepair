import sys
from itertools import permutations
from itertools import combinations
from itertools import combinations_with_replacement
#sys.stdin = open('/Users/pranjalkandhari/Desktop/Template/input.txt', 'r')

def makeThree(mat , i , j , liAns):
    liToAdd = []
    if(mat[i][j] == 1):
        liToAdd.append(i)
        liToAdd.append(j)
        mat[i][j] = 0
    
    if(mat[i+1][j] == 1):
        liToAdd.append(i+1)
        liToAdd.append(j)
        mat[i+1][j] = 0
    
    if(mat[i][j+1] == 1):
        liToAdd.append(i)
        liToAdd.append(j+1)
        mat[i][j+1] = 0
    
    if(mat[i+1][j+1] == 1):
        liToAdd.append(i+1)
        liToAdd.append(j+1)
        mat[i+1][j+1] = 0

    liAns.append(liToAdd)

def makeTwo(mat , i , j , liAns):
    liToAdd = []
    liAllCoord = [(i,j) , (i+1,j) , (i,j+1) , (i+1,j+1)]
    flag = 0
    for coord in liAllCoord:
        #print(mat[coord[0]][coord[1]])
        if(mat[coord[0]][coord[1]] == 1 and flag == 0):
            flag = 1
            liToAdd.append(coord[0])
            liToAdd.append(coord[1])
        
        if(mat[coord[0]][coord[1]] == 0):
            liToAdd.append(coord[0])
            liToAdd.append(coord[1])
    a = 0
    #print('makeTwo' , liToAdd)
    while(a<6):
        #print('46 A' , a)
        initial = mat[liToAdd[a]][liToAdd[a+1]]
        if(initial == 1):
            mat[liToAdd[a]][liToAdd[a+1]] = 0
        else:
            mat[liToAdd[a]][liToAdd[a+1]] = 1
        a+=2
    
    liAns.append(liToAdd)
    makeThree(mat , i , j , liAns)

def makeOne(mat , i , j , liAns):
    liToAdd = []
    liAllCoord = [(i,j) , (i+1,j) , (i,j+1) , (i+1,j+1)]
    ctr = 0
    for coord in liAllCoord:
        if(mat[coord[0]][coord[1]] == 1):
            liToAdd.append(coord[0])
            liToAdd.append(coord[1])
        if(mat[coord[0]][coord[1]] == 0 and ctr<2):
            ctr += 1
            liToAdd.append(coord[0])
            liToAdd.append(coord[1])
    a = 0
    while(a<6):
        initial = mat[liToAdd[a]][liToAdd[a+1]]
        if(initial == 1):
            mat[liToAdd[a]][liToAdd[a+1]] = 0
        else:
            mat[liToAdd[a]][liToAdd[a+1]] = 1
        a+=2
    
    liAns.append(liToAdd)
    makeTwo(mat , i , j , liAns)

def makeFour(mat , i , j , liAns):
    liAllCoord = [(i,j) , (i+1,j) , (i,j+1) , (i+1,j+1)]
    ctr = 0
    liToAdd = []
    for coord in liAllCoord:
        if(ctr>=3):
            break
        ctr += 1
        liToAdd.append(coord[0])
        liToAdd.append(coord[1])
        mat[coord[0]][coord[1]] = 0
    liAns.append(liToAdd)
    makeOne(mat , i , j , liAns)

for _ in range( int(input()) ):
    liStr = input().split()
    p = int(liStr[0])
    q = int(liStr[1])

    mat = [] #Matrix of size pXq
    for _ in range(0,p):
        liStr = list(input())
        li = []
        for i in liStr:
            li.append(int(i))
        mat.append(li)

    #print(mat)

    liAns = [] #List of tuple of 6 elements.

    i = 0
    while(i<p):
        j = 0
        while(j<q):

            if(i == (p-1)):
                i = i-1
            if(j == (q-1)):
                j = j-1
            
            ctr = 0
            if(mat[i][j] == 1):
                ctr += 1
            if(mat[i+1][j] == 1):
                ctr += 1
            if(mat[i][j+1] == 1):
                ctr += 1
            if(mat[i+1][j+1] == 1):
                ctr += 1
            
            if(ctr == 1):
                makeOne(mat , i , j , liAns)
            if(ctr == 2):
                makeTwo(mat , i , j , liAns)
            if(ctr == 3):
                makeThree(mat , i , j , liAns)
            if(ctr == 4):
                makeFour(mat , i , j , liAns)

            j += 2
        i += 2
    print(len(liAns))
    for sixNum in liAns:
        for a in sixNum:
            print(a+1 , end = ' ')
        print()