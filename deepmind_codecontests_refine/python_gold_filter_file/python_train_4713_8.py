t = int(input())
for _ in range(t):
    s = input()
    x = int(input())
    n = len(s)
    ans = ['1']*n
    for i in range(n):
        if s[i]=='0':
            if x+i<n:
                ans[i+x]='0'
            if i>=x:
                ans[i-x]='0'
    tmp = 0
    for i in range(n):
        if s[i]=='1':
            if x+i<n and ans[i+x]=='1':
                continue
            else:
                if i>=x and ans[i-x]=='1':
                    continue
                else:
                    tmp = -1
                    break
    if tmp==-1:
        print(-1)
    else:
        a = ''
        for i in ans:
            a+=i
        print(a)