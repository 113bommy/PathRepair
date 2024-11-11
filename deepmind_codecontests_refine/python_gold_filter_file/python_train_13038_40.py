def main():
    t=int(input())
    
    while t:
        t=t-1

        m,n = map(int,input().split())

        x = m*n

        if x%2:
            print(int(x/2) + 1)
        else:
            print(int(x/2))


if __name__ == '__main__':
    main()