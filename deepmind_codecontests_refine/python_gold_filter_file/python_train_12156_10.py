if __name__ == '__main__':
    n, m = map(int, input().split())
    a = ["." * (m + 2)] + [".%s." % (input()) for _ in range(n)] + ["." * (m + 2)]
    b = [["."] * (m + 2) for i in range(n + 2)]

    convert = lambda c: 1 if str(c) == "." else c if str(c) == "*" else c + 1

    for i in range(1, n + 1):
        if "*" in set(a[i]):
            for d in range(m + 2):
                if a[i][d] == "*":
                    b[i][d] = "*"
                    b[i][d - 1] = convert(b[i][d - 1])
                    b[i][d + 1] = convert(b[i][d + 1])
                    b[i - 1][d - 1] = convert(b[i - 1][d - 1])
                    b[i - 1][d + 1] = convert(b[i - 1][d + 1])
                    b[i - 1][d] = convert(b[i - 1][d])
                    b[i + 1][d] = convert(b[i + 1][d])
                    b[i + 1][d - 1] = convert(b[i + 1][d - 1])
                    b[i + 1][d + 1] = convert(b[i + 1][d + 1])
    for i in range(1, n + 1):
        if a[i][1:m + 1] != "".join(["%s" % (i) for i in b[i]])[1:m + 1]:
            print("NO")
            break
    else:
        print("YES")
