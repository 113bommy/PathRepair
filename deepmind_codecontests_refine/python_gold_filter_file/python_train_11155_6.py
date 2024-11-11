def main():
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    for i in range(1, n):
        x = arr[i]
        if x == 2:
            if arr[i - 1] == 3:
                ans -= 100000000000
                break
            else:
                ans += 3
                if i > 1 and arr[i - 2] == 3:
                    ans -= 1
        elif x == 3:
            if arr[i - 1] == 2:
                ans -= 100000000000
                break
            else:
                ans += 4
        elif arr[i - 1] == 2:
            ans += 3
        else:
            ans += 4
    if ans < 0:
        print("Infinite")
    else:
        print("Finite")
        print(ans)
    return 0

main()