# https://codeforces.com/problemset/problem/45/J

def solve(n, m):
    if n*m == 1:
        return [[1]]
    
    if n*m <= 3 or (n == 2 and m == 2):
        return -1
    
    a = [[0] * m for _ in range(n)]
    
    base1 = 1
    base2 = (n*m) // 2 + 1
    
    for i in range(n):
        for j in range(m):
            if (i+j) % 2 == 0:
                a[i][j] = base2
                base2+=1
            else:
                a[i][j] = base1
                base1+=1
    return a

def pr(a, n, m):
    if a == -1:
        print(a)
    else:    
        for _ in range(n):
            print(' '.join([str(x) for x in a[_]]))

n, m = map(int, input().split())
pr(solve(n, m), n, m)        