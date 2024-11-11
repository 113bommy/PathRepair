test_case_num = int(input())

for i in range(test_case_num):
    a = int(input())
    list = []
    for k in range(a):
        list.append(input())
    x= list[0][1]
    y= list[1][0]
    z = list[a-1][a-2]
    p = list[a-2][a-1]

    if x=='0' and y=='0' and z=='0' and p=='1': #0001
        print(1)
        print(a, a-1)
    elif x=='0' and y=='0' and z=='1' and p=='0': #0010
        print(1)
        print(a-1, a)
    elif x=='1' and y=='0' and z=='0' and p=='0': #1000
        print(1)
        print(2, 1)
    elif x=='0' and y=='1' and z=='0' and p=='0': #0100
        print(1)
        print(1,2)
    elif x=='1' and y=='1' and z=='1' and p=='1': #1111
        print(2)
        print(1,2)
        print(2,1)
    elif x=='0' and y=='0' and z=='0' and p=='0': #0000
        print(2)
        print(1,2)
        print(2,1)
    elif x=='0' and y=='0' and z=='1' and p=='1': #0011
        print(0)
    elif x=='1' and y=='1' and z=='0' and p=='0': #1100
        print(0)
    elif x=='0' and y=='1' and z=='0' and p=='1': #0101
        print(2)
        print(1,2)
        print(a-1, a)
    elif x=='0' and y=='1' and z=='1' and p=='0': #0110
        print(2)
        print(1,2)
        print(a,a-1)
    elif x=='0' and y=='1' and z=='1' and p=='1' : #0111
        print(1)
        print(2,1)
    elif x=='1' and y=='0' and z=='0' and p=='1' : #1001
        print(2)
        print(1,2)
        print(a,a-1)
    elif x=='1' and y=='0' and z=='1' and p=='0' : #1010
        print(2)
        print(1,2)
        print(a-1,a)
    elif x=='1' and y=='0' and z=='1' and p=='1' : #1011
        print(1)
        print(1,2)
    elif x=='1' and y=='1' and z=='0' and p=='1' : #1101
        print(1)
        print(a-1,a)
    elif x=='1' and y=='1' and z=='1' and p=='0' : #1110
        print(1)
        print(a, a-1)
