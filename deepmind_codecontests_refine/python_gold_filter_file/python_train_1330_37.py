a = int(input())
b = a%10
print("hon" if b in [2,4,5,7,9] else "pon" if b in [0,1,6,8] else "bon")