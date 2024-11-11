


def pro(f,m,s):
    # rock .. scir
    # paper .... rock
    # scri...paper
    dic={'rock':'scissors','paper':'rock','scissors':'paper'}
    b=['F','M','S']
    a=[f,m,s]
    for i in range(3):
        flg=True
        for j in range(3):
            if(i==j):
                continue
            if(dic[a[i]]==a[j]):
                continue
            else:
                flg=False
        if(flg):
            print(b[i])
            return
    print('?')


a=input()
b=input()
c=input()
pro(a,b,c)


    