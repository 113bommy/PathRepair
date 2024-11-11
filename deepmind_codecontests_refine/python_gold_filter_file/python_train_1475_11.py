if __name__ == '__main__':
    n = int(input())
    aa = list(map(int, input().split()))
    aa.sort()
    d = 0
    i = 0
    for i in range(n):
        if aa[i] >= d + 1:
            d += 1
    print(d)
        