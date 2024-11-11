def fun(s):
    cnt = 1
    ans = []
    cas = []
    num = []

    for i in range(len(s)):
        if i == 0:
            flag = s[i]
            continue
        if s[i] != s[i - 1]:
            cas.append(s[i - 1])
            if cnt > 1:
                ans.append(s[i - 1] + s[i - 1])
                num.append(2)
                cnt = 1
            else:
                ans.append(s[i - 1])
                num.append(1)
        else:
            cnt += 1
        if i == len(s) - 1:
            cas.append(s[i])
            if cnt > 1:
                num.append(2)
                ans.append(s[i] + s[i])
            else:
                num.append(1)
                ans.append(s[i])

    for i in range(1, len(num)):
        if num[i] > 1 and num[i - 1] > 1:
            ans[i] = cas[i]
            num[i] -= 1

    print(''.join(ans))

s = list(input())
# print(s)

if len(s) > 1:
    fun(s)
else:
    print(''.join(s))