if __name__ == "__main__":
    n, m = map(int, input().split())
    sum = 0
    suma = 0
    arr = [0] * n
    for i in range(n):
        a, b = map(int, input().split())
        suma += a
        arr[i] = a - b
        sum += b
    if sum > m:
        print(-1)
    elif suma <= m:
        print(0)
    else:
        comp = 0
        arr.sort(reverse=True)
        for i in range(n):
            comp += arr[i]
            if comp >= suma - m:
                print(i + 1)
                break
        else:
            print(n)
