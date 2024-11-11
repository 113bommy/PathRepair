N = int(input())

while N >= 0:
    if N % 4 == 0:
        print("Yes")
        exit()
    N -= 7
print("No")