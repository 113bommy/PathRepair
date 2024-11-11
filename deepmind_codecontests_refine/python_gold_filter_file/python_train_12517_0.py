sent=input()
flag=False
symbols=['Q','H','9']
for i in sent:
    if i in symbols:
        print('YES')
        flag=True
        break
    else:
        continue
if flag==False:
    print('NO')

