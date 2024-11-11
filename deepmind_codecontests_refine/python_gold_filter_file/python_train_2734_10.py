if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        n = int(input())
        arr = list(map(int, input().split()))
        arr.sort()
        if any(abs(arr[i]-arr[i+1])>1 for i in range(n-1)):
            print("NO")
        else:
            print("YES")
        