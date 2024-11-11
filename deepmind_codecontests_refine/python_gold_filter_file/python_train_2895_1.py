s = input()
n = s[::2].count("1")+s[1::2].count("0")
print(min(n,len(s)-n))