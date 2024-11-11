s = input()
MOD = 998244353
cnt_r = []
cnt_b = []
for i in s:
    cnt_r.append(2-int(i))
    cnt_b.append(int(i))
cursum_cnt_r = [0]*(len(s)+1)
cursum_cnt_b = [0]*(len(s)+1)
for i in range(len(s)):
    cursum_cnt_r[i+1] = cursum_cnt_r[i] + cnt_r[i]
    cursum_cnt_b[i+1] = cursum_cnt_b[i] + cnt_b[i]
cursum_cnt_r = cursum_cnt_r + [cursum_cnt_r[-1]]*len(s)
cursum_cnt_b = cursum_cnt_b + [cursum_cnt_b[-1]]*len(s)

#dp[ni][ri]:nこのボールを並べたときに赤色のボールがri個含まれるときの並べ方総数
dp = [[0]*(2*len(s)+1) for i in range(2*len(s)+1)]
dp[0][0] = 1
for ni in range(1,2*len(s)+1):
    for ri in range(0,ni+1):
        if ri == 0:
            if 0 <= ni <= cursum_cnt_b[ni]:
                #青色を選ぶ
                dp[ni][ri] = dp[ni-1][ri]
        elif ri == ni:
            if 0 <= ri <= cursum_cnt_r[ni]:
                #赤色を選ぶ
                dp[ni][ri] = dp[ni-1][ri-1]
        else:
            if 0 <= ri <= cursum_cnt_r[ni] and 0 <= ni-ri <= cursum_cnt_b[ni]:
                dp[ni][ri] += dp[ni-1][ri]
                dp[ni][ri] += dp[ni-1][ri-1]
        dp[ni][ri] %= MOD 

print(max(dp[2*len(s)]))