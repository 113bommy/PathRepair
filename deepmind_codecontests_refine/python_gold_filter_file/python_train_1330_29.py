N = input()
if N[-1] == '3':
    print('bon')
elif N[-1] in '0168':
    print('pon')
else:
    print('hon')