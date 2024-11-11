


a = int(input())


if 0<a<=127:
    print('byte')
elif a<32768:
    print('short')
elif a<2147483648:
    print('int')
elif a<9223372036854775808:
    print('long')
else:
    print('BigInteger')
