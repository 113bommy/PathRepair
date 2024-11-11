import sys

def lpre(w):
    kk = len(w)
    ww = w[:]
    w.reverse()
    ww += ['1']*kk + w
    dp = [0]*(3*kk+1)
    # dp[0] = 0
    # for i in range(1, 2*kk):
    #     k = dp[i-1]
    #     # if ww[dp[i-1]] == ww[i]:
    #     #     dp[i] = dp[i-1] + 1
    #     while k > 0 and ww[k] != ww[i]:
    #         k = dp[k-1]
    #     if k == 0 and ww[0] != ww[i]:
    #         k = -1
    #     dp[i] = k + 1
    #     # print(dp)
    dp[0] = -1
    for i in range(3*kk):
        k = dp[i]
        # if ww[dp[i-1]] == ww[i]:
        #     dp[i] = dp[i-1] + 1
        while k >= 0 and ww[k] != ww[i]:
            k = dp[k]
        # if k == 0 and ww[0] != ww[i]:
        #     k = -1
        dp[i+1] = k + 1
        # print(dp)
    
    # print(ww)
    # print(dp)
    return min(kk, dp[-1])
 


# lpre(list("abacabax"))
# lpre(list("bbabacbbabb"))
# lpre(list("babb"))
# lpre(list("bcbcbaxbcbcbcy"))
# print(lpre(list("")))
# print(lpre(list("aa")))

for q in range(int(sys.stdin.readline())):
    w = list(sys.stdin.readline().strip())
    n = len(w)
    st = 0
    for i in range(n//2):
        if w[i] == w[n-1-i]:
            st += 1
        else:
            break
    if st == n//2:
        sys.stdout.write("".join(w) + '\n')
        continue
    a = w[st:n-st]
    # print(a)
    l1 = lpre(a)
    
    # a.reverse()
    # print(a)
    l2 = lpre(a)
    # a.reverse()
    # print("half: ",w[:st], w[n-st:])
    # print(l1, l2)
    # print(a)
    if l1 > l2:
        
        ans = w[:st] + a[:l1] + w[n-st:]
    else:
        ans = w[:st] + a[len(a)-l2:] + w[n-st:]
    # if len(ans) > n:
    #     sys.stdout.write("".join(w) + '\n')
    #     continue
    sys.stdout.write("".join(ans) + '\n')
    
    



