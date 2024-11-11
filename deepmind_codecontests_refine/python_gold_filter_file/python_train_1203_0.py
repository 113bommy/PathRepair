s=input()
v="AEIOUY"
prev=-1
maxi=0
for i in range(len(s)):
    if s[i] in v:
        maxi=max(maxi,i-prev)
        prev=i
maxi=max(maxi,len(s)-prev)
print(maxi)
    
