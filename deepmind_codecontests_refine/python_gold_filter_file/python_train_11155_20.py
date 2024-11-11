n = int(input())
fg = list(map(int, input().split()))
s = 0
b = True
for i in range(n - 1):
    if (fg[i] == 1) & (fg[i + 1] == 2):
        if i > 0:
            if fg[i - 1] == 3:
                s += 2
            else:
                s += 3
        else:
            s += 3
    elif (fg[i] == 1) & (fg[i + 1] == 3):
        s += 4
    elif (fg[i] == 2) & (fg[i + 1] == 1):
        s += 3
    elif (fg[i] == 3) & (fg[i + 1] == 1):
        s += 4
    else:
        print('Infinite')
        b = False
        break
if b:
    print('Finite')
    print(s)
