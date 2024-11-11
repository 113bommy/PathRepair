if __name__ == "__main__":
    n = int(input())
    if n <= 2:
        print("No")
        exit(0)
    print("Yes")
    evens = range(2, n + 1, 2)
    odds = range(1, n + 1, 2)
    print(len(evens), " ".join(map(str, evens)))
    print(len(odds), " ".join(map(str, odds)))
