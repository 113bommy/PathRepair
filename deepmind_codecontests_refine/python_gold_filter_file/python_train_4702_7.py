stack =[1]
ans = 0
g = []
code = []
n=int(input()) 
for i in range(n):
    line = input()
    if line == 'add':
        ans +=stack[-1]
    elif line == 'end':
        stack.pop()
    else:
        a = int(line.split()[-1])
        b = stack[-1]
        stack.append(min(a*b, 2**32))

if(ans >= 2**32):
    print("OVERFLOW!!!")
else:
    print(ans) 

