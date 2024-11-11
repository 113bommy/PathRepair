#!/usr/bin/env python3

def main():
    import sys
    def I(): return int(sys.stdin.readline())
    def LI(): return list(map(int,sys.stdin.readline().split()))

    n = I()
    V = []
    W = []

    maxL = 10**5
    m = min(n, 1 << 10)
    dp = [[0]*(maxL + 1)]
    
    for i in range(n):
        v, w = LI()
        if i <= m:
            d_ = dp[(i+1)>>1][:]
            for j in range(w, maxL+1)[::-1]:
                d_[j] = max(d_[j], d_[j - w] + v)
            dp.append(d_)
        V.append(v)
        W.append(w)
    
    q = I()
    for i in range(q):
        v, L = LI()
        if v <= m:
            print(dp[v][L])
            continue
        cnt = 0
        v_ = []
        w_ = []
        while v > m:
            v_.append(V[v-1])
            w_.append(W[v-1])
            v >>= 1
            cnt += 1
        ret = dp[v][L]
        v_tmp = [0] * (1 << cnt)
        w_tmp = [0] * (1 << cnt)
        for b in range(1, 1 << cnt):
            lsb = b & -b
            l = lsb.bit_length()
            w_t = w_tmp[b - lsb] + w_[l-1]
            w_tmp[b] = w_t
            if w_t <= L:
                v_t = v_tmp[b - lsb] + v_[l-1]
                v_tmp[b] = v_t
                ret = max(ret, v_t + dp[v][L - w_t])
        print(ret)
    return

if __name__ == "__main__":
    main()
