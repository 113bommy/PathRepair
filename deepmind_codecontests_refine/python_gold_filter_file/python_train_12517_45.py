inputString = list(input())
n = len(inputString)
check = False

for i in range (0, n):
    if inputString[i] == 'H' or inputString[i] == 'Q' or inputString[i] == '9':
        check = True
        break

if check:
    print("YES")
else:
    print("NO")
