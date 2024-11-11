s = input()
s = s.lower()
for i in s:
    if i == 'a' or i == 'i' or  i == 'o' or  i == 'e' or  i == 'u' or  i == 'y' :
        s = s.replace(i, '')
for i in s:
    print("."+i, end='')