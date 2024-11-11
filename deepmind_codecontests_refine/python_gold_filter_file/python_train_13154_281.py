line=input()
n=len(line)
s=set([])
for i in range(n):
    s.add(line[i])
if len(s)%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")
    
    
