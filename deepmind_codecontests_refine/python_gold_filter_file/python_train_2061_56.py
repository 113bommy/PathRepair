N=str(input())
if 'L' in N[0::2] or 'R' in N[1::2]:
    print('No')
else:
    print('Yes')