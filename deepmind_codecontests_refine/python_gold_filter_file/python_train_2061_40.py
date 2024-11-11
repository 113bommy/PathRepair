s = input()
arr = list(s)
if 'L' in arr[::2] or 'R' in arr[1::2]:
    print('No')
else:
    print('Yes')