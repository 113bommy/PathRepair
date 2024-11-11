t = int(input())

for _ in range(t):
    s = input()
    
    cnt = 0
    for l in range(1, 19):
        lead = 0
        val = 0
        for i in range(len(s)):
            d = int(s[i])
            if i <= l-1:
                val += d * 2**(l-i-1)
            else:
                d2 = int(s[i-l])
                val -= d2 * (2 ** (l - 1))
                val *= 2
                val += d
                if d2 == 0:
                    lead += 1
                else:
                    lead = 0

            if i >= l-1 and s[i-l+1] == '1' and lead + l >= val :
                cnt += 1
    print(cnt)
