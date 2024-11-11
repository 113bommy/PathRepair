n = int(input())
s = input()
t = input()
a = [[0,0,0],[0,0,0],[0,0,0]]
b = ['a','b','c']
a[b.index(s[0])][b.index(s[1])] = 1
a[b.index(t[0])][b.index(t[1])] = 1
tr = a[0][0] + a[1][1] + a[2][2]
print("YES")
if (s == t):
    if (s[0] == s[1]):
        print("abc"*n)
    else:
        i = 0
        while b[i] == s[0] or b[i] == s[1]:
            i += 1
        print(s[0]*n + b[i]*n + s[1]*n)
else:
    max_row_sum = 0
    for i in range(3):
        if a[i][0] + a[i][1] + a[i][2] > max_row_sum:
            max_row_sum = a[i][0] + a[i][1] + a[i][2]
            index = i
    max_col_sum = 0
    for i in range(3):
        if a[0][i] + a[1][i] + a[2][i] > max_col_sum:
            max_col_sum = a[0][i] + a[1][i] + a[2][i]
            index_col = i
    if tr == 2:
        print('abc'*n)
    elif tr == 0 and max_row_sum == 2:
        i = 0
        while i == index:
            i += 1
        j = 0
        while i == j or index == j:
            j += 1
        print(b[i]*n + b[j]*n + b[index]*n)
    elif tr == 1:
        for i in range(3):
            for j in range(3):
                if a[i][j] and i != j:
                    for k in range(3):
                        if k != i and k != j:
                            print((b[j] + b[i] + b[k])*n)
    else:
        if max_col_sum == 2:
            i = 0
            while i == index_col:
                i += 1
            j = 0
            while i == j or index_col == j:
                j += 1
            print(b[index_col]*n + b[j]*n + b[i]*n)
        elif (s[0] == t[1] and s[1] == t[0]):
            i = 0
            while b[i] == s[0] or b[i] == s[1]:
                i += 1
            print(s[0]*n + b[i]*n + s[1]*n)
        else:
            i = 0
            while a[index][i] != 0 or i == index:
                i += 1
            for j in range(3):
                if j != index and j != i:
                    print((b[index] + b[i] + b[j])*n)
            

