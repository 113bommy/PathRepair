for _ in range(int(input())):
    a, b, k = map(int, input().split())
    s = input()
    ans = 0


    i = len(s)-1
    while i > -1:
        if s[i-1] == 'A' and k >= a:
            k -= a
            i -= 1
            while i> 0 and  s[i-1] == s[i]:
                i -= 1
        elif s[i-1] == 'B' and k >= b:
            k -= b
            i -= 1
            while i > 0 and s[i-1] == s[i]:
                i -= 1
        else:
            ans = i
            break
    print(ans+1)

