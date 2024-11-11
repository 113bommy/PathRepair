s=input()
print(["No","Yes"][len(set(s))==2 and s.count(s[0])==2])