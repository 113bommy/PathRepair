while True:
    n = input()
    if n == "0000":
        break

    if n.count(n[0]) == 4:
        print("NA")
        continue

    cnt = 0
    while n != "6174":
        L, S = list(n), list(n)
        L.sort(reverse=True)
        S.sort()
        n = str(int("".join(L)) - int("".join(S))).zfill(4)
        cnt += 1

    print(cnt)