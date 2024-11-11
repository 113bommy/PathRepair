def main():
    N, M = map(int, input().split(" "))
    for i in range(M // N, 0, -1):
        if M % i == 0 and i <= M / N:
            print(i)
            break


if __name__ == '__main__':
    main()