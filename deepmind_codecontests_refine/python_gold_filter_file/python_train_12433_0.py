first_row = input()
second_row = input()
third_row = input()
c = 0
o = 0
for i in range(0,3):
    if first_row[i] == 'X':
        c = c + 1
    elif first_row[i] == '0':
        o = o + 1
for i in range(0,3):
    if second_row[i] == 'X':
        c = c + 1
    elif second_row[i] == '0':
        o = o + 1
for i in range(0,3):
    if third_row[i] == 'X':
        c = c + 1
    elif third_row[i] == '0':
        o = o + 1

r = 0
if first_row[0] == "X" and second_row[1] == "X" and third_row[2] == "X":
    r = 1+r
if first_row[0] == "X" and second_row[0] == "X" and third_row[0] =="X":
    r = 1+r
if first_row[0] == "X" and first_row[1] == "X" and first_row[2]== "X":
    r = 1+r
if first_row[1] == "X" and second_row[1] == "X" and third_row[1] == "X":
    r = 1+r
if first_row[2] == "X" and second_row[2] == "X"  and third_row[2] == "X":
    r = 1+r
if first_row[2] == "X" and second_row[1] == "X" and third_row[0] == "X":
    r = 1+r
if second_row[0] == "X" and second_row[1] == "X" and second_row[2] == "X":
    r = r + 1
if third_row[0] == "X" and third_row[1] == "X" and third_row[2] == "X":
    r = r + 1
    
q  = 0
if first_row[0] == "0" and second_row[1] == "0" and third_row[2] == "0":
    q = 1+q
if first_row[0] == "0" and second_row[0] == "0" and third_row[0] =="0":
    q = 1+q
if first_row[0] == "0" and first_row[1] == "0" and first_row[2] == "0":
    q = q + 1
if first_row[1] == "0" and second_row[1] == "0" and third_row[1]== "0":
    q = 1 + q

if first_row[2] == "0" and second_row[2] == "0" and third_row[2] == "0":
    q = 1 + q
if first_row[2] == "0" and second_row[1] == "0" and third_row[0] == "0":
    q = 1 + q
if second_row[0] == "0" and second_row[1] == "0" and second_row[2] == "0":
    q = q + 1
if third_row[0] == "0" and third_row[1] == "0" and third_row[2] == "0":
    q = q + 1            
    
if first_row[0] == "X" and first_row[2] == "X" and third_row[0] == "X" and third_row[2] == "X" and first_row[1] == "0" and second_row[0] == "0" and second_row[2] == "0" and third_row[1] == "0" and second_row[1] == "X":
    print("the first player won")
elif first_row[0] == "X" and first_row[1] == "X" and third_row[2] == "X" and second_row[2] == "X" and second_row[1] == "0" and third_row[1] == "0" and third_row[0] == "0" and second_row[0] == "0" and first_row[2] == "X":
    print("the first player won")
elif first_row[2] == "0" and first_row[1] == "0" and first_row[0] == "X" and second_row[2] == "0" and second_row[1] == "0" and third_row[1] == "X" and third_row[2] == "X" and second_row[0] == "X" and third_row[0] == "X":
    print("the first player won")
elif first_row[2] == "0" and first_row[1] == "X" and first_row[0] == "0" and second_row[2] == "X" and second_row[0] == "X" and third_row[1] == "X" and third_row[2] == "0" and third_row[0] == "0" and second_row[1] == "X":
    print("the first player won")
elif first_row[2] == "0" and first_row[1] == "0" and first_row[0] == "X" and second_row[2] == "X" and second_row[1] == "X" and third_row[1] == "0" and third_row[2] == "0" and third_row[0] == "X" and second_row[0] == "X":
    print("the first player won")
elif first_row[2] == "X" and first_row[1] == "0" and first_row[0] == "0" and second_row[0] == "X" and second_row[1] == "X" and third_row[1] == "0" and third_row[2] == "X" and third_row[0] == "0" and second_row[2] == "X":
    print("the first player won")
elif first_row[0] == "X" and first_row[1] == "X" and first_row[2] == "X" and second_row[2] == "0" and second_row[0] == "X" and second_row[2] == "0" and third_row[0] == "X" and third_row[1] == "0" and third_row[2] == "0":  
    print("the first player won")
elif c-o > 1 or (o-c) >= 1 or (r==1 and q == 1):
    print("illegal")
elif q >= 1 and r == 0:
    if c == o:
        print("the second player won")
    else:
        print("illegal")
elif r >= 1 and q == 0:
    if c-1 == o:
        print("the first player won")
    else:
        print("illegal")
elif c - o == 1 and o+c != 9:
    print("second")
elif c-o == 0:
    print("first")
else:
    print("draw")
