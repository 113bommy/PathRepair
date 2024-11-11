a = int(input())
b = int(input())
print("YES") if int(''.join(str(a).split('0'))) + int(''.join(str(b).split('0'))) == int(''.join(str(a+b).split('0')))else print("NO")