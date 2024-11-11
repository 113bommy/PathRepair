a = input()
a = int(a)
if -128 <= a <= 127:
    print(r'byte')
elif -32768 <= a <= 32767:
    print(r'short')
elif -2147483648 <= a <= 2147483647:
    print(r'int')
elif -9223372036854775808 <= a <= 9223372036854775807:
    print(r'long')
else:
    print(r'BigInteger')