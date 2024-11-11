def main():
    n = int(input())
    a = list(map(int, input().split()))
    chest = biceps = back = 0
    for i in range(n):
        if (i + 1) % 3 == 0:
            back += a[i]
        elif (i + 1) % 3 == 2:
            biceps += a[i]
        else:
            chest += a[i]
    if back > biceps and back > chest:
        print("back")
    elif biceps > chest:
        print("biceps")
    else:
        print("chest")

if __name__ == '__main__':
    main()
