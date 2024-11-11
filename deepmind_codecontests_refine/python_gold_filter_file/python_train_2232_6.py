a,b,c,d = map(int,input().split())
x = str(input())
cal = 0
for i in range(len(x)):
    if int(x[i]) == 1:
        cal += a
    elif int(x[i]) == 2:
        cal +=b
    elif int(x[i]) == 3:
        cal += c
    elif int(x[i]) == 4:
        cal += d
print(cal)