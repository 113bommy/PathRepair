def fun(ans, s):
    for i in range(len(s)):
        if s[i] == "1":
            if i-x >= 0 and ans[i-x] == "1":
                continue
            if i +x < len(s) and ans[i+x] == "1":
                continue
            return False
    return True


for _ in range(int(input())):
    s = input()
    x = int(input())
    n = len(s)
    ans = ["1"]*n
    for i in range(n):
        if s[i] == "0":
            if i-x >=0:
                ans[i-x] = "0"
            if i+x < n:
                ans[i+x] = "0"
    ret = "".join(ans)
    chk = fun(ans, s)
    if not chk:
        print(-1)
    else:
        print(ret)