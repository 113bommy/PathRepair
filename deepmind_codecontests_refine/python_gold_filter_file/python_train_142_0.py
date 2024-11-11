s = input()
l=[]
for i in s:
    if (i != '+'):
        l.append(int(i))
l.sort()

st=''
for j in l:
    st = st+'+'+str(j)
print(st[1:])



        