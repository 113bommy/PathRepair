letter='aAoOyYeEuUiI'
string=input()
result=''
for i in string:
    if not (i in letter):
        i=i.lower()
        result+='.'+i
print(result)
