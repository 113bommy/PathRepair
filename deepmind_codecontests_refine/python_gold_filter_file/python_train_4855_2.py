K = int(input())
if K <= 3 or (K % 2 != 0 and K % 3 != 0):
    print(1)
    exit()
i = K
while i >= 1:
    if K % i == 0:
        Binary = bin(i)[2:]
        if "01" not in str(Binary) and Binary.count('0') - Binary.count('1') == -1:
            print(i)
            exit()
    i -= 1
