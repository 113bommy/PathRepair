def main():
    m = int(input())
    a = list(map(int, input().split()))
    for i in range(1, m):
        if a[i] % a[0] != 0:
            print(-1)
            exit()
    print(2*m - 1)
    print(a[0], end=' ')
    for i in range(1, m):
        print(a[i], a[0], end=' ')
main()