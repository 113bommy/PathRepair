n = int(input())
s = list(input())

if n == 1:
    print(0)
    print(s[0])
else:
    ans = 0
    for i in range(1, n-1):
        if s[i] == s[i-1]:
            if s[i-1] != 'R' and s[i+1] != 'R':
                s[i] = 'R' 
            elif s[i-1] != 'B' and s[i+1] != 'B':
                s[i] = 'B'
            else:
                s[i] = 'G'
            ans += 1

    i = -1
    if s[-1] == s[-2]:
        if s[i-1] != 'R':
            s[i] = 'R' 
        elif s[i-1] != 'B':
            s[i] = 'B'
        else:
            s[i] = 'G'
        ans += 1
    print(ans)
    print(''.join(s))


        