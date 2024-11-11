for i in range(int(input())):
    s, intel, e = map(int, input().split())
    min_s = max(0, (intel - s + e + 2)//2)
    print(max(e - min_s + 1, 0))