s=input()
se=[]
vo=['a','e','i','o','u','A','E','I','O','U','Y','y']
for i in range(len(s)):
    if s[i] not in vo:
        se.append(s[i])
for i in range(len(se)):
    print('.'+se[i].lower(),end='')
