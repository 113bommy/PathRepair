n = int(input());
s = input();
check = False;
for i in range(len(s) - 1):
    if(s[i] > s[i + 1]):
        print('YES');
        print(i + 1,i + 2);
        check = True;
        break;
if(check == False):
    print('NO')
