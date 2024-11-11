a=input()
b=int(a[1])
a=a[0]
if (a=='h' or a=='a') and (b==1 or b==8):
    print('3')
elif a=='h' or a=='a' or b==1 or b==8:
    print('5')
else:
    print('8')