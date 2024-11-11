pn = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

a, b = input().split()

fa = -1
fb = -1

for i in range(len(pn)):
    if pn[i] == int(a):
        fa = i
    elif pn[i] == int(b):
        fb = i

if fb - fa == 1:
    print("YES")
else:
    print('NO')
