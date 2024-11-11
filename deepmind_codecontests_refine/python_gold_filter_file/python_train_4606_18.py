n = int(input())
s = "{:06b}".format(n)
#print(s)
res = s[0] + s[5] + s[3] + s[2] + s[4] + s[1]
#print(res)
print(int(res, 2))