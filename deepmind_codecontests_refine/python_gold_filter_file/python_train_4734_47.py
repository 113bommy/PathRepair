a = str(input())

a= a.replace("?","")
a= a.replace(" ","")

last_letter= str(a[-1])
vowel= ['a','e','i','o','u','A','E','I','O','U','Y','y']

if last_letter in vowel:
    print("YES")
else:
    print("NO")