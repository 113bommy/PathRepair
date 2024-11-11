n = int(input())
y = False
for i in range(n//1234567 + 2):
    for j in range((n - 1234567*i)//123456 + 2):
        a = n - i*1234567 - j*123456
        if a >=0 and a%1234 == 0:
            y = True
            break

if(y):
    print("YES")
else:
    print("NO")