n = int(input())
k = 0
j = 0
for i in range(n):
    x, y = input().split()
    x = int(x)
    y = int(y)
    if(x, y) > (0, 0):
        k = k + 1
    elif(x, y) < (0, 0):
        j = j + 1
if( k == n):
    print("Yes")
elif( j == n):
    print("Yes")
elif( k == 1):
    print("Yes")
elif(j == 1):
    print("Yes")
else:
    print("No")
