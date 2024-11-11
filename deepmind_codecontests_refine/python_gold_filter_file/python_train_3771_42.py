while True:
    try:
        n = int(input())
        s = input()
        a = ''
        b = ''
        a += s[0]
        ans = '0'
        for i in range(1,n):
            if s[i]>=a[-1]:
                a += s[i]
                ans += '0'
            elif b=='' or s[i]>=b[-1]:
                b += s[i]
                ans += '1'
            else:
                ans = 'N'
                break
        if ans=='N':
            print('NO')
        else:
            print('YES')
            print(ans)
                
    except EOFError:
        break
