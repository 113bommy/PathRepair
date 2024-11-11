def GetListFromInput():
    return list(map(int, input().split()))

def CloneMatrix(matrix):
    return [list(row) for row in matrix]

def SwapColumns(matrix, i, j):
    n = len(matrix)
    for row in range(n):
        matrix[row][i], matrix[row][j] = matrix[row][j], matrix[row][i]

def CanMatrixBeSorted(matrix):
    for row in matrix:
        unordered_elements = 0
        for j, element in enumerate(row):
            invalid_order = j+1 != element
            if invalid_order:
                unordered_elements += 1

            invalid_row = unordered_elements > 2
            if invalid_row:
                return False
    return True


def SolveB():
    # Input
    n, m = GetListFromInput()
    matrix = []
    for i in range(n):
        next_row = GetListFromInput()
        matrix.append(next_row)

    # Bruteforce algorithm
    for i in range(m):
        for j in range(m):
            new_matrix = CloneMatrix(matrix)
            SwapColumns(new_matrix, i, j)
            if CanMatrixBeSorted(new_matrix):
                return True
    return False


def main():
    answer = "YES" if SolveB() else "NO"
    print(answer)

main()

