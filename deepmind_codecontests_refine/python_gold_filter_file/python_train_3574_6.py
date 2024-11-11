def main():
    inp1 = [int(j) for j in input().split(" ")]
    inp2 = [int(j) for j in input().split(" ")]
    n = inp1[0]
    x = inp1[1]
    srt_l = sorted(inp2)
    cpos = -1
    m = int((n + 1) / 2) - 1
    diff = n
    for i in range(n):
        if x == srt_l[i] and abs(i - m) < diff:
            # print("present in list")
            cpos = i
            diff = abs(i - m)
    flag = 0
    diff = n
    if cpos == -1:
        # print("not present in list")
        cpos = 0

        flag = 1

        for i in range(n + 1):
            if i == 0:
                a = -1
            else:
                a = srt_l[i - 1]
            if i == n:
                b = x
            else:
                b = srt_l[i] 
            if a <= x and x <= b and abs(i - m) <= diff:
                cpos = i
                diff = abs(i - m)
        n += 1

    ans = -1
    m = int((n + 1) / 2) - 1
    # print("m is: ", m)
    # print("cpos is: ", cpos)
    if cpos < m:
        # print("cpos < n+1/2")
        ans = n - 2 * cpos - 2
        if (cpos + ans) == (int((n + ans + 1) / 2) - 1):
            # print("found ans ", ans)
            pass
        elif (cpos + ans + 1) == (int((n + ans + 1 + 1) / 2) - 1):
            ans = ans + 1
        elif (cpos + ans - 1) == (int((n + ans + 1 - 1) / 2) - 1):
            ans = ans - 1
    elif cpos == m:
        ans = 0
    else:
        ans = 2 * cpos - n + 1
        if (cpos) == (int((n + ans + 1) / 2) - 1):
            # print("found ans ", ans)
            pass
        elif (cpos) == (int((n + ans + 1 + 1) / 2) - 1):
            ans = ans + 1
        elif (cpos) == (int((n + ans - 1 - 1) / 2) - 1):
            ans = ans - 1
    if flag:
        ans = ans + 1
    print(ans)


main()
