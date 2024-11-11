s=input()
a=['a','e','i','o','u','1','3','5','7','9']
count=0
for i in range(len(s)):
    if s[i] in a:
        count+=1
print(count)