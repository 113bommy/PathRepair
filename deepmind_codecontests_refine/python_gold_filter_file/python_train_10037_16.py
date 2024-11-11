import sys

s=list(input())
n=len(s)
if n<=2:
    print(''.join(s))
    sys.exit()
temp=['/',s[0],s[1]]
for i in range(2,n):
    if s[i]==temp[-1] and s[i]==temp[-2]:
        continue 
    elif temp[-2]==temp[-3] and s[i]==temp[-1]:
        continue 
    else:
        temp.append(s[i])
x=''.join(temp[1:])
print(x)
        
        



    