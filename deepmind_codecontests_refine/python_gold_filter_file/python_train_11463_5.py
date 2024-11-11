def main():
    a, b = map(int, input().split())
    mx = max(a, b)
    mn = min(a, b)
    s = mx + mn
    k = int(0.5 * ((1 + 8 * s) ** 0.5 - 1))
    rk = range(k, 0, -1)
    # rk = range(1, k + 1)
    st = {i: True for i in rk}

    # k1 = min(k, mn)
    r1, r2 = mn, mx
    xe, ie = 0, 0
    for k in rk:
        if k <= r1:
            st[k] = "min"
            ie += 1
            r1 -= k
        else:
            st[k] = "max"
            xe += 1
            r2 -= k

    if a == mx:
        a_k, b_k = "max", "min"
        a_q, b_q = xe, ie
    else:
        a_k, b_k = "min", "max"
        a_q, b_q = ie, xe

    print(a_q)
    for e in st:
        if st[e] == a_k:
            print(e, end=" ")
    print()

    print(b_q)
    for e in st:
        if st[e] == b_k:
            print(e, end=" ")
    print()


if __name__ == "__main__":
    main()
