def main():
    m,n = map(int,input().split())

    c = ""

    for i in range(m):
        x = input()

        x = x.split()

        for i in x:
            if i in ['C', 'M', 'Y']:
                c = "#Color"

    if c:
        print(c)
    else:
        print("#Black&White")


if __name__ == '__main__':
    main()