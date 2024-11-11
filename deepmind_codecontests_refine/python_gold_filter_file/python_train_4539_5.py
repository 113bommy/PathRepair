a=input()
a=a.replace('VK','AA')
z=a.count('A')//2
a=a.replace('VV','W')
a=a.replace('KK','W')
if 'W' in a:
    z+=1
print(z)
