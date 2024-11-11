def main():
    mod = 998244353
    s, k = input().split()
    k, n, one, cnt, z, zero_list = int(k), len(s), s.count("1")+1, 0, 0, []
    for i in range(n):
        if s[i] == "0":
            zero_list.append(cnt)
            cnt = 0
        else:
            cnt += 1
    mm = min(one-1, k)

    dp = [[0]*(mm+1) for _ in [0]*one]
    dp[0][0] = 1

    for i in zero_list:
        dp2 = [[0]*(mm+1) for _ in [0]*one]
        for jl in range(z+i, one):
            for x in range(i, min(one, jl+1, mm+i+1)):
                dp2[jl][x-i] = (dp2[jl][x-i]+sum([dp[jl-x+p][p]
                                                  for p in range(min(one, x-i+1))])) % mod
            for p in range(min(one, mm+1)):
                dp2[jl][p] = (dp2[jl][p]+sum([dp[jl-l][p]
                                              for l in range(min(one, i, jl-p+1))])) % mod
        z += i
        dp = dp2
    print(sum([sum(i) for i in dp]) % mod)


main()
