n=input()
s=n[::2].count("0")+n[1::2].count("1")
print(min(s,len(n)-s))