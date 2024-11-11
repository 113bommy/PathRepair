
t = int(input())
for  _ in range(t):
    n = int(input())
    
    matrix = []
    for i in range(n):
        matrix.append(list(map(int,input().split())))
    
    bothday = []
    for i in range(6):
        for j in range(i+1,5):
            bothday.append([i,j])

    found = False
    for i,j in bothday:
        ci = 0
        cj = 0
        cnot = 0
        for s in range(n):
            ci += matrix[s][i]
            cj += matrix[s][j]
            
            if matrix[s][j] == 0 and matrix[s][i]==0:
                cnot+=1
        
        if ci >= n//2 and cj >= n//2 and cnot == 0:
            found = True
            break
    if found:
        print("YES")
    else:
        print("NO")