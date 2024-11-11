def main():
    a, b, c, d = map(int, input().split())
    print(a / b / (1 - (b - a) * (d - c) / (b * d)))


if __name__ == '__main__':
    main()
