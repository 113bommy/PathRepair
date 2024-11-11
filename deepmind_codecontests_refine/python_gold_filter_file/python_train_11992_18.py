n=int(input())
s=input()
a=s.count("z")
b=s.count("n")
for i in range(0,b):
    print("1",end=" ")
for i in range(0,a):
    print("0",end=" ")