n = int(input())
s = input()
g = 0
r = 0
b = 0
for i in s:
    if i == 'R':
        r = r+1
    elif i == 'G':
        g = g+1
    else:
        b= b+1
if b == n:
    print('B')
elif g == n:
    print("G")
elif r == n:
    print("R")
elif b >= 1 and g>=1 and r>=1:
    print("BGR")
elif b>1 and (g == 1 or r == 1):
    print("GR")
elif g>1 and (b==1 or r ==1):
    print("BR")
elif r>1 and (g == 1 or b==1):
    print("BG")
elif (b>1 and (g>1 or r>1)) or (g>1 and(b>1 or r>1)) or (r>1 and(b>1 or g>1 )):
    print("BGR")
elif b == 1 and r == 1:
    print("G")
elif b == 1 and g == 1:
    print("R")
elif r == 1 and g == 1:
    print("B")