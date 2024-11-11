s=input()
new=''
g=''
_c=0
_two=False
for u in s:
    if u!=g:
        if _c>=2: _two=True
        if _c==1: _two=False
        _c=1
        new=new+u
        g=u

    else:
        if _c<2 and _two==False:
            new=new+u
            g=u

            _c+=1
print(new)