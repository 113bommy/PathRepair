n = input()

tmp = len(n)-1

if int(n[0] + tmp*'9') == int(n):
    print(9*tmp + int(n[0]))
else:
    print(9*tmp + int(n[0])-1)