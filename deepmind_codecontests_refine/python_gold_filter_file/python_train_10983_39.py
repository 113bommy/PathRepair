s=input()
low=0
up=0
for i in range(len(s)):
    if s[i]>="a" and s[i]<="z":
        low+=1
     
    elif s[i]>="A" and s[i]<="Z":
        up+=1
       
if low>=up:
    s=s.lower()
else:
    s=s.upper()
print(s)
    
        
        

