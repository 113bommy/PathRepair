N = int(input())
k = N % 4
if k == 1:
    print(0,"A",sep=" ")
elif k == 2:
    print(1,"B",sep=" ")
elif k == 3:
    print(2,"A",sep=" ")
elif k == 0:
    print(1,"A",sep=" ")
