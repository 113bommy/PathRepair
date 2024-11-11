symbols = "AHIMOTUVWXY"
def check(s):

    ls = len(s)
    if ls == 1:

        return "YES" if s[0] in symbols else "NO"

    else:

        if (ls % 2 == 1 and s[ls // 2] not in symbols):

            return "NO"

        for i in range(ls // 2):

            ch_l, ch_r = s[i], s[-i - 1]
            if not (ch_l == ch_r and ch_l in symbols):

                return "NO"

        return "YES"

print(check(input()))
