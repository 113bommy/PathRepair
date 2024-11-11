s = input().lstrip("0")
r = input().lstrip("0")
if(s == r):
    print('=')
elif(len(s) > len(r) or (len(s) == len(r) and s > r)):
    print('>')
else:
    print('<')
