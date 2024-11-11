def main():
    n = int(input())
    # n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    # a, b = map(int, input().split())
    # s = input()
    x = 1
    for el in arr:
        x *= el
    for i in range(0, n, 2):
        print(arr[i + 1], -arr[i], end=' ')
    print()



# for _ in range(1):
for _ in range(int(input())):
    main()
