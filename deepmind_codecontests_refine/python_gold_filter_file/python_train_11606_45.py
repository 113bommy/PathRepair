"""
    Maximum in Table
"""
def getValue(i,j):
    if(i == 1 or j == 1):
        return 1
    """ table[i,j] = table[i, j-1] + table[i-1, j] """
    return getValue(i, j-1) + getValue(i-1, j)
n = int(input())
print(getValue(n,n))