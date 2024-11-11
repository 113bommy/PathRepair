li=['A','E','I','O','U','Y','y','a','e','i','o','u']
str1=input()
out="."
for i in str1:
    if i not in li:
        if out[-1] != '.':
            out=out+'.'
        out+=i.lower()
print(out)