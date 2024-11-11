if __name__ == '__main__':
    res = []
    t = int(input())

    for i in range(t):
        n = int(input())
        res.append(n)

    for r in res:
        arr = [str(i + 2) for i in range(r)]
        print(' '.join(arr))
