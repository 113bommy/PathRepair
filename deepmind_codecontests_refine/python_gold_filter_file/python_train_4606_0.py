n = bin(int(input()))[2:].rjust(6, '0')
s = n[0] + n[5] + n[3] + n[2] + n[4] + n[1]
print(int(s, 2))