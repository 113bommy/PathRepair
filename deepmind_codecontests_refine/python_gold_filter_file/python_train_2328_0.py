if __name__ == '__main__':
    n, m, v = (int(_) for _ in input().split())

    if m < n - 1:
        print(-1)
    elif m > (n - 1) * (n - 2) / 2 + 1:
        print(-1)
    else: 
        v = v % n
        print((v - 1) % n + 1, v + 1) 
        for i in range(1, n - 1):
            print((v + i) % n + 1, (v + i + 1) % n + 1) 

        m -= (n - 1)

        i = 1
        while m > 0:
            j = 2
            while m > 0 and j < n - i + 1:
                if (v + i + j) % n != v:
                    print((v + i) % n + 1, (v + i + j) % n + 1)
                    m -= 1
                j += 1
            i += 1
