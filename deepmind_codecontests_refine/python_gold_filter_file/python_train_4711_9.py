for i in range(int(input())):
    n = int(input())
    s = list(map(int, input().split())); s.sort()
    a = []; b = []
    s1 = []; s1.append(abs(s[0] - s[1]))
    for i in range(1, n - 1):
        s1.append(abs(s[i] - s[i + 1]))
    print(min(s1))