if __name__ == '__main__':
    arr = [int(__) for __ in input().strip().split()]
    x = sum(arr) / 5
    if int(x) != x or x == 0:
        print(-1)
    else:
        print(int(x))
