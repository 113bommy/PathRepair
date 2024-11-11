S = input()
if 'R' in S[1::2] or 'L' in S[0::2]:
    print('No')
else:
    print('Yes')