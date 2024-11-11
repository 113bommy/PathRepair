s=input()
count=0
for i in range (len(s)):
    if(s[i]=='a'or s[i]=='e'or s[i]=='i'or                              s[i]=='o'or s[i]=='u'):
        count+=1
    elif(s[i]=='1'or s[i]=='3'or s[i]=='5'or s[i]=='7'or s[i]=='9'):
        count+=1
print(count)