def main():
    n, q = map(int, input().split())
    cnt = [0] * (n+1)
    ll = [0] * q
    rr = [0] * q

    for i in range(q):
        l, r = map(int, input().split())
        cnt[l] += 1
        if r < n:
            cnt[r+1] -= 1
        ll[i] = l
        rr[i] = r

    for i in range(1, n+1):
        cnt[i] += cnt[i-1]

    pref1 = [0] * (n+1)
    pref2 = [0] * (n+1)
    for i in range(1, n+1):
        if cnt[i] == 1:
            pref1[i] = 1
        pref1[i] += pref1[i-1]

        if cnt[i] == 2:
            pref2[i] = 1
        pref2[i] += pref2[i-1]

    all = 0
    for i in range(1, n+1):
        if cnt[i] > 0:
            all += 1


    def getIntersection(l1, r1, l2, r2):
        start = max(l1, l2)
        end = min(r1, r2)
        if start <= end:
            return start, end
        return None


    maxBlocks = 0
    for i in range(q):
        for j in range(i+1, q):
            all_ij = all
            inter = getIntersection(ll[i], rr[i], ll[j], rr[j])
            if inter:
                interL, interR = inter
                all_ij -= (pref1[interL-1] - pref1[min(ll[i], ll[j])-1])
                all_ij -= (pref1[max(rr[i], rr[j])] - pref1[interR])
                all_ij -= (pref2[interR] - pref2[interL-1])
            else:
                all_ij -= (pref1[rr[i]] - pref1[ll[i]-1])
                all_ij -= (pref1[rr[j]] - pref1[ll[j]-1])

            maxBlocks = max(maxBlocks, all_ij)

    print(maxBlocks)


if __name__ == '__main__':
    main()