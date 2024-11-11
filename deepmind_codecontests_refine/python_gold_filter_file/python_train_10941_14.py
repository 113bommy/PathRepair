
n = int(input())

A, B, C, AB, AC, BC, ABC = [], [], [], [], [], [], []

check_A, check_B, check_C = False, False, False


for i in range(0,n):
    price, vitamins = [x for x in input().split(' ')]
    if vitamins == 'A':
        A.append(int(price))
        check_A = True
    elif vitamins == 'B':
        B.append(int(price))
        check_B = True
    elif vitamins == 'C':
        C.append(int(price))
        check_C = True
    elif vitamins == 'AB' or vitamins == 'BA':
        AB.append(int(price))
        check_A = True
        check_B = True
    elif vitamins == 'AC' or vitamins == 'CA':
        AC.append(int(price))
        check_A = True
        check_C = True
    elif vitamins == 'BC' or vitamins == 'CB':
        BC.append(int(price))
        check_B = True
        check_C = True
    else:
        ABC.append(int(price))
        check_A = True
        check_B = True
        check_C = True

ans=[]

if not (A == [] or B == [] or C == []):
    ans.append(min(A)+ min(B)+ min(C))

if not (A == [] or BC == []):
    ans.append(min(A)+ min(BC))
    
if not (B == [] or AC == []):
    ans.append(min(B)+ min(AC))
    
if not (C == [] or AB == []):
    ans.append(min(C)+ min(AB))
    
if not (AB == [] or BC == []):
    ans.append(min(AB)+ min(BC))
    
if not (BC == [] or AC == []):
    ans.append(min(BC)+ min(AC))
    
if not (AC == [] or AB == []):
    ans.append(min(AC)+ min(AB))
    
if not (ABC == []):
    ans.append(min(ABC))


if check_A == True and check_B == True and check_C == True:
    print(min(ans))
else:
    print(-1)
    
