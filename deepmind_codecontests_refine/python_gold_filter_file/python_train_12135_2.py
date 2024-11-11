n, m = [int(x) for x in input().split()]
L = [[int(x) for x in input().split()] for i in range(n)]
def solve(L):
    D = {i:set() for i in range(n)}
    for i in range(n):
        for j in range(m):
            if L[i][j] != j+1:
                D[i].add((min(j+1, L[i][j]), max(j+1, L[i][j])))
                if len(D[i]) > 3 or len(D[i]) == 3 and L[i][L[i][j]-1] == j+1:
                    return False
    if all((len(D[i]) < 2) for i in range(n)):
        return True
    for x in range(m):
        for y in range(x,m):
            for i in range(n):
                if not ((x+1,y+1) in D[i] or len(D[i]) == 0):
                    break
            else:
                return True
    return False

print('YES') if solve(L) else print('NO')
