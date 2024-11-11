def mp():
    return map(int, input().split())

n = int(input())
s = input()
t = input()

if s[1] == t[1] and s[0] != t[0] and s[1] != s[0] and t[1] != t[0]:
    print('YES')
    print(s[1] * n + s[0] * n + t[0] * n)
elif s[0] == t[0] and s[1] != t[1] and s[0] != s[1] and t[0] != t[1]:
    print('YES')
    print(s[1] * n + t[1] * n + s[0] * n)
else:
    for w in ['a', 'b', 'c']:
        ans = [w]
        cnt = [0, 0, 0]
        cnt[ord(w) - 97] += 1
        for i in range(3 * n - 1):
            p = ans[-1]
            may = [1] * 3
            if s[0] == p:
                may[ord(s[1]) - 97] = 0
            if t[0] == p:
                may[ord(t[1]) - 97] = 0
            
            jj = -1
            for j in range(3):
                if may[j] and cnt[j] < n and (jj == -1 or cnt[j] <= cnt[jj]):
                    jj = j
            if jj == -1:
                break
            ans.append(chr(jj + 97))
            cnt[jj] += 1  
            
        if len(ans) == 3 * n:
            print('YES')
            print(''.join(ans))
            break
    else:
        for w in ['a', 'b', 'c']:
            ans = [w]
            cnt = [0, 0, 0]
            cnt[ord(w) - 97] += 1
            for i in range(3 * n - 1):
                p = ans[-1]
                may = [1] * 3
                if s[0] == p:
                    may[ord(s[1]) - 97] = 0
                if t[0] == p:
                    may[ord(t[1]) - 97] = 0
                
                jj = -1
                for j in range(3):
                    if may[j] and cnt[j] < n and (jj == -1 or cnt[j] < cnt[jj]):
                        jj = j
                if jj == -1:
                    break
                ans.append(chr(jj + 97))
                cnt[jj] += 1  
                
            if len(ans) == 3 * n:
                print('YES')
                print(''.join(ans))
                break
        else:
            print('NO')