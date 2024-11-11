n = int(input())
A = []
for i in range (n):
    s = input()
    A.append('#' + s + '#')
A.append('#' * (n + 2))
A.append('#' * (n + 2))
for i in range (n):
    for j in range (1, n + 1):
        #for k in range (n + 2):
        #    print(A[k])
        #print(i, j)
        #print()
        #print()
        if A[i][j] == '.':
            A[i] = A[i][:j] + '#' + A[i][j + 1:]
            if A[i + 1][j - 1] == A[i + 1][j] == A[i + 1][j + 1] == A[i + 2][j] == '.':
                A[i + 1] = A[i + 1][:j - 1] + '#' + A[i + 1][j:]
                A[i + 1] = A[i + 1][:j] + '#' + A[i + 1][j + 1:]
                A[i + 1] = A[i + 1][:j + 1] + '#' + A[i + 1][j + 2:]
                A[i + 2] = A[i + 2][:j] + '#' + A[i + 2][j + 1:]
            else:
                print("NO")
                exit()
print("YES")