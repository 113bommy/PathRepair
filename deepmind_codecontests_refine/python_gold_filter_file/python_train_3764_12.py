def findNumbers(x1, x2, x3, x4):
    a = x4 - x3
    b = x4 - x2
    c = x4 - x1
    return " ".join(str(i) for i in [a, b, c])

if __name__ == "__main__":
    x1, x2, x3, x4 = sorted(map(int, input().split()))
    print(findNumbers(x1, x2, x3, x4))