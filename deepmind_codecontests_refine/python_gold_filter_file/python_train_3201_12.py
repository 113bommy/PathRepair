k = int(input())
a = input()
if (a.count('11') >= 1 or a.count('000') >= 1) == 1:
    print('No')
elif (k == 1) and (a[0] == '0'):
    print('No')
elif (k >= 2) and(a[0] + a[1] == '00' or a[-1] + a[-2] == '00'):
    print('No')
else:
    print('Yes')
