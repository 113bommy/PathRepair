n=int(input())
s=input()
zero,ones=0,0
for i in s:
    if i=='0': zero+=1
    else: ones+=1
A=[]
for i in s:
    A.append(i)
n=len(s)
if zero==ones:
    print(2)
    print(''.join(A[:n-1]),A[-1])
else:
    print(1)
    print(s)