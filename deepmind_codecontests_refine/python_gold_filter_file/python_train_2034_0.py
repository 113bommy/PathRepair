a=int(input())
if a>=-128 and a<=127:
    print('byte')
elif a>=-32768 and a<=32767:
    print('short')
elif a>=-2147483648 and a<=2147483647:
    print('int')
elif a>=-9223372036854775808 and a<=9223372036854775807:
    print('long')
else:
    print('BigInteger')
