for i in range(int(input())):
    input();
    l = [int(i) for i in input().split()]
    flag = 0; s = 0 ; e  = 0;
    for i in range(len(l)-1):
        if(abs(l[i] - l[i+1]) >= 2):
            flag = 1
            s = i+1 ; e = i+2;
    if(flag):
        print('YES')
        print(s,e)
    else:
        print('NO')


