s = int(input())
if -128 <= s <= 127 :
    print('byte')
elif -32768 <= s <= 32767:
    print('short')
elif -2147483648 <= s <= 2147483647:
    print('int')
elif -9223372036854775808 <= s <= 9223372036854775807:
    print('long')
else:
    print('BigInteger')