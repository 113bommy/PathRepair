t = int(input())
for i in range(t):
    s = input()
    m = 0
    l = [-1] * 3
    # print(l)

    for j in range(len(s)):

        l[int(s[j]) - 1] = j
        # print(l,int(s[j]))

        if l[0] > -1 and l[1] > -1 and l[2] > -1:
            if m == 0:
                m = max(l) - min(l) + 1
                # print("if m",m)

            else:
                m = min(m, max(l) - min(l) + 1)
                # print("else", m)
    print(m)