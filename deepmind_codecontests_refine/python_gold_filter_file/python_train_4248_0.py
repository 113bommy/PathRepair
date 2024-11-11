n=int(input())
if n%2==1:print(0);exit()
A=0
add=10
while n>=add:
    A +=n//add
    add *=5
print(A)