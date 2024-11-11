def main():
    n = int(input())
    for i in range(n):
        for j in range(n):
            if (i+j) % 2:
                print('B', end='')
            else:
                print('W', end='')
        
        print()


if __name__ == "__main__":
    main()
