def main():
    n = int(input())
    m = int(input())
    data = []
    for i in range(n):
        data.append(int(input()))
    data.sort(reverse=True)
    s = 0
    for i, v in enumerate(data):
        s = s + v
        if s >= m:
            print(i + 1)
            return


if __name__ == "__main__":
    main()
