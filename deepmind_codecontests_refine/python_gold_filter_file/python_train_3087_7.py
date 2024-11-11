n=int(input())
s=input()
def test(x):
    dic='aeiouy'
    if dic.find(x)!=-1:
        return 1
    else:
        return 0

res=[]
flg=0
for x in s:
    if not flg:
        res.append(x)
        if test(x):
            flg=1
        else:
            pass
    else:
        if not test(x):
            flg=0
            res.append(x)
        else:
            pass
print(''.join(res))
        