import sys

if __name__ == '__main__':
    stdin = sys.stdin
    test_case = int(stdin.readline())

    while test_case:
        test_case -= 1

        # read in this case
        s = stdin.readline().rstrip()

        # position of the next one to the left for each bit
        nxt_one = [0] * len(s)
        nxt_one[0] = -1 # there are no one to the left of the first bit
        tmp = -1 if s[0] == '0' else 0
        for i in range(1, len(s)):
            nxt_one[i] = tmp
            if s[i] == '1':
                tmp = i

        # 2^18 > 2*10^5
        # only ones inbetween 17 distance of the current testing bit is candidate
        # test starting from each bit
        ans = 0
        for i in range(len(s)):
            # search left
            cur = 0
            # try combine with ones within 17 bit
            new_one = nxt_one[i] if s[i] == '0' else i
            while i - new_one < 18 and new_one != -1:
                # set cur num
                cur |= 1 << (i - new_one)
                # try if expending string with 0 is possible
                if cur <= i - nxt_one[new_one]:
                    ans += 1
                # iterate, consider adding the next one
                new_one = nxt_one[new_one]

        print(ans)
