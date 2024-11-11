n=int(input())
s=input()
z=s.count('z')
n=s.count('n')
for i in range(n):
    print(1,end=" ")
for i in range(z):
    print(0,end=" ")