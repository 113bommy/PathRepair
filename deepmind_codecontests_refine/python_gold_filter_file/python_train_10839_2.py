if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        arr = [int(num) for num in input().split()]
        a = 0
        if arr[0] != arr[1]:
            if arr[2] % 2 == 0:
                a += (arr[2] // 2) * (arr[0] - arr[1])
            else:
                a += (arr[2] // 2 + 1) * arr[0]
                a -= (arr[2] // 2) * arr[1]
            print(a)
        else:
            if arr[2]%2 == 0:
                print(0)
            else:
                print(arr[0])