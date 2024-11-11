


if __name__=='__main__':
    l,p = map(lambda x:int(x),input().strip().split(' '))

    s = list(input())
    i = 0
    periodFlag = True
    for i in range(len(s)-p):
        if s[i] == '.' and s[i+p] =='.':
            periodFlag = False
            s[i] = '0'
            s[i+p] = '1'
            break
        elif s[i] == '.' and s[i+p] == '0':
            s[i] = '1'
            periodFlag = False
            break
        elif s[i] =='.' and s[i+p] == '1':
            s[i] = '0'
            periodFlag = False
            break
        elif s[i+p] == '.' and s[i] == '0':
            s[i+p] = '1'
            periodFlag=False
            break
        elif s[i+p] == '.' and s[i] == '1':
            s[i+p] = '0'
            periodFlag = False
            break
        elif s[i] != s[i+p]:
            periodFlag= False
            break


    if periodFlag:
        print('No')
    else:
        for i in range(len(s)):
            if s[i] == '.':
                s[i] = '0'
        print(''.join(s))




