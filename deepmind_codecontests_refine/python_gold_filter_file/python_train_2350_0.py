a,b = input(), input()
s = ""
for i in range(len(a)):
        x, y = str(max(a[i], b[i])), str(min(a[i], b[i]))
        if (x in s and x+y not in s) or (y in s and x+y not in s):
                print('-1')
                exit()
        if x+y not in s:
                s +=" " + x + y
lis = []
for i in s.split():
        if i[0] != i[1]: lis.append(i[0] + " " + i[1])
print(len(lis))
for i in lis:
        print(i)