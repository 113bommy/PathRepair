
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = [int(x) for x in input().split()]
        if len(set(arr)) == len(arr):
            print("NO")
        else:
            print("YES")