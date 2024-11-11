a = int(input())
if a % 2 == 0:
    print(int(a/2))
    print ("2 " * int((a/2)))
else:
    print(int((a//2)))
    print("2 " * int((a//2 - 1)) + "3")