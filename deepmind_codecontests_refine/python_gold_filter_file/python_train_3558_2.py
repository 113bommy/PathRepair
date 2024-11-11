dim = input().split()
n = int(dim[0])
m = int(dim[1])
A = []
for i in range(0,n):
    A.append(list(map(int, input().split())))

B = [[0 for i in range(m)] for j in range(n)]

def poscheck(A,n,m):
    for i in range(0,n):
        for j in range(0,m):
            if A[i][j] == 1:
                num = 0
                coords = [(i-1,j-1),(i,j-1),(i-1,j),(i+1,j),(i,j+1),(i+2,j),(i,j+2),(i+2,j+2)]
                for k in range(0,8):
                    try:
                        if A[coords[k][0]][coords[k][1]] == 1:
                            num += 1
                    except:
                        pass
                if num < 3:
                    return False
    return True

if A == B:
    print(0)

#elif poscheck(A,n,m) == False:
 #   print(-1)

else:
    instr = []
    for i in range(0,n):
        for j in range(0,m):
            if A[i][j] == 1:
                num = 0
                coords = [(i+1,j),(i,j+1),(i+1,j+1)]
                for k in range(0,3):
                    try:
                        if A[coords[k][0]][coords[k][1]] == 1:
                            num += 1
                    except:
                        pass
                if num == 3:
                    instr.append([i+1,j+1])
                    
    for coord in instr:
        ccoord = coord.copy()
        ccoord[0] -= 1
        ccoord[1] -= 1
        
        B[ccoord[0]][ccoord[1]] = 1
        B[ccoord[0]][ccoord[1]+1] = 1
        B[ccoord[0]+1][ccoord[1]] = 1
        B[ccoord[0]+1][ccoord[1]+1] = 1

    if A == B:
        print(len(instr))
        for coord in instr:
            print(coord[0],coord[1])

    else:
        print(-1)
