s=input()
a="qwertyuiopasdfghjkl;zxcvbnm,./"
if s=='R':
    for i in input():
        print(a[a.index(i)-1],end="")
    print()
else:
    for i in input():
        print(a[a.index(i)+1],end="")
    print()