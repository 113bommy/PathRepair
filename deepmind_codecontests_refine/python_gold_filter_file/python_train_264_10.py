import sys

matrix = []
for i in range(4):
    s = input()
    l = []
    for j in range(4):
        l.append(s[j])
    matrix.append(l)
ans = 'NO'
for i in range(4):
    for j in range(4):
        if matrix[i][j] == 'x':
            if i < 2:
                if matrix[i + 1][j] == 'x' and matrix[i + 2][j] == '.':
                    ans = 'YES'
                    print(ans)
                    sys.exit()
                if matrix[i + 1][j] == '.' and matrix[i + 2][j] == 'x':
                    ans = 'YES'
                    print(ans)
                    sys.exit()                    
            else:
                if matrix[i - 1][j] == 'x' and matrix[i - 2][j] == '.':
                    ans = 'YES'
                    print(ans)
                    sys.exit()
                if matrix[i - 1][j] == '.' and matrix[i - 2][j] == 'x':
                    ans = 'YES'
                    print(ans)
                    sys.exit()                
            if j < 2:
                if matrix[i][j + 1] == 'x' and matrix[i][j + 2] == '.':
                    ans = 'YES'
                    print(ans)
                    sys.exit()
                if matrix[i][j + 1] == '.' and matrix[i][j + 2] == 'x':
                    ans = 'YES'
                    print(ans)
                    sys.exit()                    
            else:
                if matrix[i][j - 1] == 'x' and matrix[i][j - 2] == '.':
                    ans = 'YES'
                    print(ans)
                    sys.exit()
                if matrix[i][j - 1] == '.' and matrix[i][j - 2] == 'x':
                    ans = 'YES'
                    print(ans)
                    sys.exit()            
            if i < 2 and j < 2:
                if matrix[i + 1][j + 1] == 'x' and matrix[i + 2][j + 2] == '.':
                    ans = 'YES'
                    print(ans)
                    sys.exit()
                if matrix[i + 1][j + 1] == '.' and matrix[i + 2][j + 2] == 'x':
                    ans = 'YES'
                    print(ans)
                    sys.exit()                    
            elif i >= 2 and j >= 2:
                if matrix[i - 1][j - 1] == 'x' and matrix[i - 2][j - 2] == '.':
                    ans = 'YES'
                    print(ans)
                    sys.exit()
                if matrix[i - 1][j - 1] == '.' and matrix[i - 2][j - 2] == 'x':
                    ans = 'YES'
                    print(ans)
                    sys.exit()
            if i < 2 and j >= 2:
                if matrix[i + 1][j - 1] == 'x' and matrix[i + 2][j - 2] == '.':
                    ans = 'YES'
                    print(ans)
                    sys.exit()
                if matrix[i + 1][j - 1] == '.' and matrix[i + 2][j - 2] == 'x':
                    ans = 'YES'
                    print(ans)
                    sys.exit()                
            if i >= 2 and j < 2:
                if matrix[i - 1][j + 1] == 'x' and matrix[i - 2][j + 2] == '.':
                    ans = 'YES'
                    print(ans)
                    sys.exit()
                if matrix[i - 1][j + 1] == '.' and matrix[i - 2][j + 2] == 'x':
                    ans = 'YES'
                    print(ans)
                    sys.exit()            
print(ans)