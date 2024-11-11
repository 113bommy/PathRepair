str1=str(input())

vow="AEIOUYaeiouy"

str2=""
str3=str1.lower()

for i in str3:
    if i not in vow:
        str2+="." + i



print(str2)
        
        
    
