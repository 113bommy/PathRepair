n = int(input())
x = input()
total = 0
L = 0
R = 0
for i in range(0, n) :
    if x[i] == "L" :
        L += 1
    else :
        R += 1

if n == 1 :
    total = 2
elif L == R :
    total = L + R + 1
elif L != R :
    total = L + R + 1


print(total)
