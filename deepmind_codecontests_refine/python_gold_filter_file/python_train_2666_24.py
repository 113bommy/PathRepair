N = int(input())
A = str(input())
chars = []
for i in A:
    chars.append(i)
curr = 0
mx = 0
x = len(chars)
for i in range(0,x):
    if chars[i] == ' ': 
        if curr > mx: 
            mx = curr
        curr = 0
    elif chars[i] == chars[i].upper():
            curr = curr + 1

if curr > mx:
    mx = curr
print(mx)

         

