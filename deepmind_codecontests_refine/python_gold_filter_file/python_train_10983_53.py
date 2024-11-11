string=input()
big=0
small=0
for x in string:
    if ord('a')<=ord(x)<=ord('z'):
        small=small+1
    if ord('A')<=ord(x)<=ord('Z'):
        big=big+1
if small>=big:
    string=string.lower()
else:
    
    string=string.upper()
    

print(string)
