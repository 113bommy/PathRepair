n=input()
r=n[0::2].count("0")+n[1::2].count("1")
print(min(r,len(n)-r))