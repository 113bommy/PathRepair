a=str(input())
a=a.strip(' ').strip('?').strip(' ')
a=a.casefold()
if a[-1]=='a' or a[-1]=='e' or a[-1]=='i' or a[-1]=='o' or a[-1]=='u' or a[-1]=='y':
    print("YES")
else:
    print("NO")