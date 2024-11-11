s = bin(int(input()))[2:]
s = "%06d" % int(s)
print(int(s[0]+s[5]+s[3]+s[2]+s[4]+s[1],2))