for _ in range(int(input())):
    s = str(input())
    ans = str()
    for i in range(len(s)):
        if i % 2 == 0:
            ans += ('a' if s[i] != 'a' else 'b')
        else:
            ans += ('z' if s[i] != 'z' else 'y')
    print(ans)
