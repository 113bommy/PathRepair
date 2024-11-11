for i in range(int(input())):
    n = int(input())
    if n % 2 == 0: print(n-3, 2, 1)
    else:
        rem = n-1
        if rem/2 % 2 == 0: print(rem//2 + 1, rem//2 - 1, 1)
        else: print(rem//2 + 2, rem//2 - 2, 1)