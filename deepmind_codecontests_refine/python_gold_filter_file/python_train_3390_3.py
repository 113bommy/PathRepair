a = [int(x) for x in input().split()];
color=False;
for i in range(0, a[0]):
    b=str(input());
    if(b.find('C')+b.find('M')+b.find('Y')!=-3):
        color=True;
        break;
if(color):
    print("#Color");
else:
    print("#Black&White");
