n=input()
temp=''
n=n.lower()
vowel=['a','e','i','e','o','u','A','E','I','O','U','y','Y']
for i in n:
    if i.isalpha():
        if not i in vowel:
            temp+=i

result=''
for i in temp:
    result+='.'
    result+=i
    
print(result)
