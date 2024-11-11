for testCase in range(int(input())):
    n = int(input())
    s = input()
    if n == 2:
        print(0)
        continue
    print((n - s.count("01") - s.count("10"))//2)