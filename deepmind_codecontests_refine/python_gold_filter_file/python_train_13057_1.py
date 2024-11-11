for _ in range(int(input())):
    s=input()
    a=[]
    st='X'*12
    for i in s:
        if i=='X':
            a.append("1x12")
            break;
    for i in range(6):
        if s[i]=='X' and s[i+6]=='X':
            a.append("2x6")
            break;
    for i in range(4):
        if s[i]=='X' and s[i+4]=='X' and s[i+8]=='X':
            a.append("3x4");
            break;
    for i in range(3):
        if s[i]=='X' and s[i+3]=='X' and s[i+6]=='X' and s[i+9]=='X':
            a.append("4x3");
            break
    for i in range(2):
        if s[i]=='X' and s[i+2]=='X' and s[i+4]=='X' and s[i+6]=='X' and s[i+8]=='X' and s[i+10]=='X':
            a.append("6x2")
            break
    if st==s:
        a.append("12x1")
    print(len(a),end=' ')
    for i in a:
        print(i,end=' ')
    print('')