n = int(input())
l = input()
r = input()

if n == 1:
    print(r)
elif l[0] == '0':
    print('1'*n)
elif r[-1] == '0' and int(l,2)+1 < int(r,2):
    print(r[:-1] + "1")
else:
    print(r)
