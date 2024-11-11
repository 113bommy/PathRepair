n,x = int(input()), int(input())
if ((n % 6 == 0) or (n % 6 == 5)) and x == 0 :
    print(0)
elif n == 1 and x == 0 :
    print(1)
elif n == 1 and x == 2 :
    print(2)
elif n == 2 and x == 1 :
    print(2)
elif n == 3 and x == 0 :
    print(2)
elif ((n - 2) % 6 == 0 or (n - 2) % 6 == 5)and x == 0 :
    print(1)
elif ((n - 4) % 6 == 0 or (n - 4) % 6 == 5)and x == 0:
    print(2)
elif (n % 6 == 1 or n % 6 == 4) and x == 1 :
    print(0)
elif ((n - 2) % 6 == 1 or (n - 2) % 6 == 4) and x == 1 :
    print(1)
elif ((n - 4) % 6 == 1 or (n - 4) % 6 == 4) and x == 1 :
    print(2)
elif (n % 6 == 2 or n % 6 == 3) and x == 2 :
    print(0)
elif ((n - 2) % 6 == 2 or (n - 2) % 6 == 3) and x == 2 :
    print(1)
elif ((n - 4) % 6 == 2 or (n - 4) % 6 == 3) and x == 2 :
    print(2)
