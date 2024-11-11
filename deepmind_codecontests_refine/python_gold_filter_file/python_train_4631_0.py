import sys
a = [int(x) for x in input()]
if(len(a) == 1 and a[0] == 9):
    print('9')
    sys.exit()
if(a[0] > 4 and a[0] != 9):
    a[0] = 9 - a[0]
for i in range(1, len(a)):
    if(a[i] > 4):
        a[i] = 9 - a[i]
for i in range(len(a)):
    a[i] = str(a[i])
a = ''.join(a)
a = int(a)
print(a)