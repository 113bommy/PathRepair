n, Result1, Result2, Sum, Result = int(input()), 0, 0, 0, 0
Square = [[0 for i in range(n)] for i in range(n)]
for i in range(n):
    Square[i] = list(map(int,input().split()))

if n == 1:
    print('1')
    exit()

for i in range(n):
    Sum1, Sum2, Control1, Control2 = 0, 0, 0, 0
    for j in range(n):
        Sum1, Sum2 = Sum1 + Square[i][j], Sum2 + Square[j][i]
        if Square[i][j] == 0:
            Control1 = 1
        if Square[j][i] == 0:
            Control2 = 1
    if Control1 == 1:
        Result1 = Sum1
    elif Sum == 0:
        Sum = Sum1
    elif Sum1 != Sum:
        print('-1')
        exit()
    if Control2 == 1:
        Result2 = Sum2
    elif Sum == 0:
        Sum = Sum2
    elif Sum2 != Sum:
        print('-1')
        exit()

if Result2 == Result1 and Result2 < Sum:
    Result = Sum - Result1
else:
    print('-1')
    exit()

Sum1, Sum2, Control1, Control2 = 0, 0, 0, 0
for i in range(n):
    Sum1, Sum2 = Sum1 + Square[i][i], Sum2 + Square[i][n - 1 - i]
    if Square[i][i] == 0:
        Control1 = 1
    if Square[i][n - 1 -i] == 0:
        Control2 = 1
if Control1 == 1 and Sum1 + Result != Sum:
    print('-1')
    exit()
if Control1 == 0 and Sum1 != Sum:
    print('-1')
    exit()
if Control2 == 1 and Sum2 + Result != Sum:
    print('-1')
    exit()
if Control2 == 0 and Sum2 != Sum:
    print('-1')
    exit()

print(Result)
