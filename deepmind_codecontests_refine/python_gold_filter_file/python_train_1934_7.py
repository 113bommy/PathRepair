n = int(input())
temp = n
print(n//2)
while(temp!=0):
    if(temp%2!=0):
        print("3", end=" ")
        temp -= 3
    else:
        print("2", end=" ")
        temp -= 2

