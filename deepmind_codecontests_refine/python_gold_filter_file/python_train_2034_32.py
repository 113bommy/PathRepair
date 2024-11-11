n = int(input())
# print(n)

if -128 <= n and n <= 127:
    print("byte")
elif -32768 <= n and n <= 32767:
    print("short")
elif -2147483648 <= n and n <= 2147483647:
    print("int")
elif -9223372036854775808 <= n and n <= 9223372036854775807:
    print("long")
else:
    print("BigInteger")