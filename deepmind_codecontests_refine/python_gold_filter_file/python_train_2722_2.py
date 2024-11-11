def can_cover(i,j,matrix,n):
    if (i >= 0 and i+2 < n and j-1 >= 0 and j+1 < n):
        return (matrix[i][j] == 1
               and matrix[i+1][j] == 1
               and matrix[i+2][j] == 1
               and matrix[i+1][j-1] == 1
               and matrix[i+1][j+1] == 1)
    return False

def cover(i,j,matrix,n):
    matrix[i][j] = 0
    matrix[i+1][j] = 0
    matrix[i+2][j] =0
    matrix[i+1][j-1] =0
    matrix[i+1][j+1] = 0

def tiling(matrix, n, white_c):
#    covered = [[False for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if matrix[i][j] == 1:
                if can_cover(i,j,matrix,n):
                    cover(i,j,matrix,n)
                    white_c -= 5
    if white_c == 0:
        return "YES"
    else:
        return "NO"
                
if __name__ == "__main__":
    n = int(input())
    matrix = [[0 for _ in range(n)] for _ in range(n)]
    white_c = 0
    for i in range(n):
        line = input()
        for j in range(len(line)):
            if line[j] == '.':
                matrix[i][j] = 1
                white_c += 1
    print(tiling(matrix,n, white_c))