s = 'qwertyuiopasdfghjkl;zxcvbnm,./'
keylist = list(s)
#print(keylist)
direction = input()
given = input()
st = ""
for i in given:
    j = keylist.index(i)
    if(direction == 'R'):
        st = st + keylist[j-1]
    else:
        st = st + keylist[j+1]
    
print(st)