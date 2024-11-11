n = int(input())
string = input()
l = -string.count("L")
b = string.count("R")
if l == 0:
    print(b+1)
elif b == 0:
    print(abs(l)+1)
else:
    print(abs(l)+b+1)
