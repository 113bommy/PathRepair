for _ in range(int(input())):
    a=list(input())
    if(a[0]==a[-1]):a=a
    elif(a[0]=='b'):a[0]='a'
    else:a[-1]='a'
    print(''.join(a))