s = input()
x = []
for i in range(24):
    if i<6:
        x.append('0'+str(i)+':'+str(i)+'0')
    elif i>9:
        if int(str(i)[::-1])<60:
            x.append(str(i)+':'+str(i)[::-1])
for i in x:
    if i>s:
        print(i)
        exit()
else:
    print(x[0])