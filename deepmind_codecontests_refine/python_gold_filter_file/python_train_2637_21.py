n = input()
A = input().split()
B = []
a = 0
b = 0
c = 0
d = 0
count = 0
for i in A:
    B.append(int(i))
for j in B:
    if j == 1:
        a = a + 1
    elif j == 2:
        b = b + 1
    elif j == 3:
        c = c + 1
    elif j == 4:
        d = d + 1
if c >= a:
    count = c + d + ((b-1)/2+1)
elif c < a:
    if b%2 == 0:
        count = c + d+ b/2 + ((a-c-1)/4+1)
    else:
        if (a-c) <= 2:
            count = c + d +(b-1)/2 + 1
        elif (a-c) > 2 and b!=0:
            count = c + d +(b-1)/2 + 1 + ((a-c-2-1)/4+1)
        elif (a-c) > 2 and b == 0:
            count = c + d + ((a-c-1)/4+1)
print(int(count))
    
    

