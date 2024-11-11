for _ in range(int(input())):
    vals = sorted(list(map(int, input().split())))
    if vals[2] <= vals[0] + vals[1] + 1:
        print("Yes")
    else:
        print("No")
