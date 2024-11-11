for _ in range(int(input())):
    s = input()
    t = input()
    if len(t) == 1:
        print("YES" if t in s else "NO")
        continue
    nxt = [[-1] * 26 for _ in range(len(s) + 1)]
    nxt[-2][ord(s[-1]) - ord('a')] = len(s) - 1
    for i in range(len(s) - 2, -1, -1):
        for c in range(26):
            nxt[i][c] = nxt[i + 1][c]
        nxt[i][ord(s[i]) - ord('a')] = i
    ans = "NO"
    for p in range(len(t)):
        a = t[:p]
        b = t[p:]
        dp = [[-1] * (len(b) + 1) for _ in range(len(a) + 1)]
        dp[0][0] = 0
        for la in range(len(a) + 1):
            for lb in range(len(b) + 1):
                if dp[la][lb] != -1:
                    if la < len(a):
                        if dp[la + 1][lb] != -1:
                            if nxt[dp[la][lb]][ord(a[la]) - ord('a')] != -1:
                                if nxt[dp[la][lb]][ord(a[la]) - ord('a')] < dp[la + 1][lb] - 1:
                                    dp[la + 1][lb] = nxt[dp[la][lb]][ord(a[la]) - ord('a')]
                                    dp[la + 1][lb] += 1 + min(0, dp[la + 1][lb])
                        else:
                            dp[la + 1][lb] = nxt[dp[la][lb]][ord(a[la]) - ord('a')]
                            dp[la + 1][lb] += 1 + min(0, dp[la + 1][lb])
                    if lb < len(b):
                        if dp[la][lb + 1] != -1:
                            if nxt[dp[la][lb]][ord(b[lb]) - ord('a')] != -1:
                                if nxt[dp[la][lb]][ord(b[lb]) - ord('a')] < dp[la][lb + 1] - 1:
                                    dp[la][lb + 1] = nxt[dp[la][lb]][ord(b[lb]) - ord('a')]
                                    dp[la][lb + 1] += 1 + min(0, dp[la][lb + 1])
                        else:
                            dp[la][lb + 1] = nxt[dp[la][lb]][ord(b[lb]) - ord('a')]
                            dp[la][lb + 1] += 1 + min(0, dp[la][lb + 1])
                if dp[len(a)][len(b)] != -1:
                    ans = "YES"
                    break
    print(ans)
