S = input()
S_o = S[::2]
S_e = S[1::2]
if 'L' in S_o or 'R' in S_e:
    print('No')
else:
    print('Yes')
