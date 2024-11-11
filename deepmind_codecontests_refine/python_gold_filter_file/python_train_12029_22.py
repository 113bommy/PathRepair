def main():
    n = int(input())
    for i in range((n - 1234567 if n & 1 else n) // 2, -1, -1234567):
        for j in range(i, -1, -61728):
            if not j % 617:
                print("YES")
                return
    print("NO")


if __name__ == '__main__':
    main()
