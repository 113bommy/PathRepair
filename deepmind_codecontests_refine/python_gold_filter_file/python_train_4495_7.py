myStr=input().lower()
vowels=['a','i','o','u','e','y']
newStr=''.join(['.'+l for l in myStr if l not in vowels]);
print(newStr)
