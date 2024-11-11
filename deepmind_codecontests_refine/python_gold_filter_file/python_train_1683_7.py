def main():
    k = int(input())
    n, tenPow, s = 1, 1, 0
    while ((s + 9*tenPow*n) < k):
        s += 9 * tenPow * n
        n += 1
        tenPow *= 10
    num = str(tenPow-1+(k-s+n-1)//n)
    print(num[(k-s-1)%n])

if __name__ == "__main__":
    main()

