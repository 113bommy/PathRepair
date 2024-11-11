x = input()
x = x.split(" ")
x[0] = int(x[0])
x[1] = int(x[1])
for i in range(x[1]):
    if abs(x[0]%10) == 0:
        x[0] = x[0]/10
    else:
        x[0] -= 1
print(int(x[0]))