t = int(input())

if t == 1:
    print(1)
    print(1)

else:
    i = 9
    while i >= 1:
        if t % i == 0:
            print(int(t/i))
            for j in range(int(t/i)):
                print(i, end=" ")
            break
        i = i - 1
