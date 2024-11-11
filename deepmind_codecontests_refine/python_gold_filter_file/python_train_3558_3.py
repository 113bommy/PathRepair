n, m = [int(x) for x in str(input()).split()]

a = [0]*n
b = [0]*n
for i in range(n):
    a[i] = [0]*m
    b [i] = [0]*m
#print(b)
for i in range(n):
    a[i] = [int(x) for x in str(input()).split()]

#print(b)
ans = []
for i in range(n-1):
    for j in range(m-1):
        if a[i][j] == 1 and a[i+1][j] == 1 and a[i][j+1] == 1 and a[i+1][j+1] == 1:
            if b[i][j] == 0 or b[i+1][j] == 0 or b[i][j+1] == 0 or b[i+1][j+1] == 0:
                ans.append((i+1,j+1))
                #print('b', b)
                b[i][j] = 1
                b[i+1][j] = 1
                b[i][j+1] = 1
                b[i+1][j+1] = 1
                #print('b',b)
                
#print (a)
#print(b)
#print(ans)
impos = False
for i in range(n):
    for j in range(m):
        if a[i][j] != b[i][j]: 
            impos = True
            break

if impos:
    print(-1)
else:
    print(len(ans))
    for a,b in ans:
        print(a, b)